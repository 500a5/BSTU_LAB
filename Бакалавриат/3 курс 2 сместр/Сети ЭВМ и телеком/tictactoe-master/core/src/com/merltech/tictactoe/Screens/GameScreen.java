package com.merltech.tictactoe.Screens;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Input;
import com.badlogic.gdx.Screen;
import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.Sprite;
import com.badlogic.gdx.math.Rectangle;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.scenes.scene2d.Stage;
import com.badlogic.gdx.scenes.scene2d.ui.Dialog;
import com.badlogic.gdx.scenes.scene2d.ui.Label;
import com.badlogic.gdx.scenes.scene2d.ui.Skin;
import com.badlogic.gdx.scenes.scene2d.ui.Table;
import com.badlogic.gdx.utils.Timer;
import com.badlogic.gdx.utils.viewport.ScreenViewport;
import com.merltech.tictactoe.TicTacToe;
import com.merltech.tictactoe.network.BluetoothService;
import com.merltech.tictactoe.network.Message;

public class GameScreen implements Screen {
    private final TicTacToe game;
    private final BluetoothService bluetoothService;
    private Skin skin;
    private Stage stage;
    private Sprite fieldSprite;
    private Sprite oSprite;
    private Sprite xSprite;

    private int playerValue;
    private final int[][] field;
    private Dialog dialog;
    private Label dialogLabel;
    private boolean gameRunning = false;
    private boolean hasTurn = false;
    private Rectangle[][] collisionRectangles;

    private final String Tag = "Game";

    public GameScreen(TicTacToe game) {
        this.game = game;
        this.skin = game.skin;
        this.bluetoothService = game.bluetoothService;
        playerValue = 0;
        field = new int[3][3];

        setupUi();
        oSprite = new Sprite(new Texture(Gdx.files.local("O.png")));
        xSprite = new Sprite(new Texture(Gdx.files.local("X.png")));
    }

    private int getWinner() {
        int row_sum = 0;
        int column_sum = 0;
        int diag_sum_1 = 0;
        int diag_sum_2 = 0;
        for(int a = 0; a < 3; ++a) {
            diag_sum_1 += field[a][a];
            diag_sum_2 += field[2-a][a];
        }

        for(int a = 0; a < 3; ++a) {
            row_sum = 0;
            column_sum = 0;
            for(int b = 0; b < 3; ++b) {
                row_sum += field[b][a];
                column_sum += field[a][b];
            }
            if(Math.min(row_sum, Math.min(column_sum, Math.min(diag_sum_1, diag_sum_2))) == -3) {
                return -1;
            }
            if(Math.max(row_sum, Math.max(column_sum, Math.max(diag_sum_1, diag_sum_2))) == 3) {
                return 1;
            }
        }
        return 0;
    }

    private void setupUi() {
        stage = new Stage(new ScreenViewport());

        Table rootTable = new Table(skin);
        rootTable.setFillParent(true);

        Label titleLabel = new Label("Tic Tac Toe", skin, "big-font", Color.BLACK);
        rootTable.add(titleLabel);
        rootTable.center().top();

        stage.addActor(rootTable);

        dialog = new Dialog("End Game", skin) {
            protected void result(Object object) {
                bluetoothService.disconnect();
                game.setScreen(game.lobbyScreen);
            };
        };
        dialogLabel = new Label("error", skin);
        dialog.text(dialogLabel);
        dialog.button("Okay", 1);

        fieldSprite = new Sprite(new Texture(Gdx.files.local("field.png")));
        fieldSprite.setPosition(Gdx.graphics.getWidth() / 2 - fieldSprite.getWidth() / 2, (Gdx.graphics.getHeight() - titleLabel.getHeight()) / 2 - fieldSprite.getHeight() / 2);
        Rectangle fieldRect = fieldSprite.getBoundingRectangle();
        float width = fieldRect.getWidth() / 3;
        float height = fieldRect.getHeight() / 3;
        collisionRectangles = new Rectangle[3][3];
        for(int column = 0; column < 3; ++ column) {
            for(int row = 0; row < 3; ++row) {
                collisionRectangles[column][row] = new Rectangle(fieldRect.getX() + column * width, fieldRect.getY() + row * height, width, height);
            }
        }
    }

    private void processMessages() {
        Message message = null;
        while((message = bluetoothService.getMessage()) != null) {
            Gdx.app.log(Tag, "received message: " + message.code.name());
            switch(message.code) {
                case BLUETOOTH_CONNECTED:
                    Gdx.app.log(Tag, "we have a connection");
                    gameRunning = true;
                    // cancel the connection timeout
                    Timer.instance().clear();
                    break;
                case BLUETOOTH_ADAPTER_DISABLED:
                case BLUETOOTH_DISCONNECTED:
                case BLUETOOTH_ERROR:
                    // this is bad, we have to stop the game
                    if(!gameRunning) {
                        // we have no problem if the game is already over
                        break;
                    }
                    gameRunning = false;
                    showDialog("Error", "bluetooth error: " + message.code.name());
                    break;
                case BLUETOOTH_SENT:
                    Gdx.app.log(Tag, "bluetooth was sent");
                    break;
                case BLUETOOTH_RECEIVED:
                    String received = new String((byte[])message.data);
                    int column = Integer.parseInt(received.substring(0, 1));
                    int row = Integer.parseInt(received.substring(1, 2));
                    String opponentString = received.substring(2,3);
                    int opponentValue = opponentString.equals("X") ? 1 : -1;
                    field[column][row] = opponentValue;
                    checkWinner();
                    hasTurn = true;
                    break;
                default:
                    Gdx.app.log(Tag, "message not handled, discarded");
            }
        }
    }

    private void checkWinner() {
        int winner = getWinner();
        if(winner == 0) {
            boolean draw = true;
            for(int column = 0; column < 3; ++column) {
                for(int row = 0; row < 3; ++row) {
                    if(field[column][row] == 0)
                        draw = false;
                }
            }
            if(draw) {
                showDialog("Game over", "It is a draw");
                gameRunning = false;
            }
            return;
        }
        if(winner == playerValue) {
            showDialog("Game over", "You won :)");
            gameRunning = false;
            return;
        }
        showDialog("Game over", "You lost like a noob");
        gameRunning = false;
    }

    private void showDialog(String title, String message) {
        dialog.getTitleLabel().setText(title);
        dialogLabel.setText(message);
        dialog.show(stage);
    }

    @Override
    public void show() {
        Gdx.app.log(Tag, "showing");
        game.inputMultiplexer.addProcessor(stage);
        // reset field and buttons
        for(int column = 0; column < 3; ++column) {
            for(int row = 0; row < 3; ++row) {
                field[column][row] = 0;
            }
        }

        // if we are not already connected we came here to host a game
        if(!bluetoothService.isConnected()) {
            bluetoothService.listen();
            // we are the host, so our id is -1
            playerValue = -1;
            // the client always begins

            // schedule a timeout because we are only visible for 30 seconds
            Timer.schedule(new Timer.Task() {
                @Override
                public void run() {
                    showDialog("Timeout", "No client connected");
                }
            }, 30);

            // we need to show the user that he is waiting, could be some fancy animation someday :)
            gameRunning = false;
            hasTurn = false;
        } else {
            // we are just a client so our id is 1
            playerValue = 1;

            //no need to wait
            gameRunning = true;
            hasTurn = true;
        }
    }

    @Override
    public void render(float delta) {
        if(Gdx.input.isKeyJustPressed(Input.Keys.BACK)) {
            Gdx.app.log(Tag, "back key was pressed, returning to lobby");
            bluetoothService.disconnect();
            game.setScreen(game.lobbyScreen);
        }
        if(Gdx.input.justTouched() && gameRunning && hasTurn) {
            // the screen was tapped and we are allowed to take a turn
            float x = Gdx.input.getX();
            float y = Gdx.graphics.getHeight() - Gdx.input.getY();
            for(int column = 0; column < 3; ++ column) {
                for(int row = 0; row < 3; ++row) {
                    if(collisionRectangles[column][row].contains(new Vector2(x, y))) {
                        if(field[column][row] == 0) {
                            Rectangle rect = collisionRectangles[column][row];
                            hasTurn = false;
                            // a play is allowed here
                            field[column][row] = playerValue;
                            String position = String.valueOf(column) + String.valueOf(row);
                            String data = playerValue == 1 ? position + "X" : position + "O";
                            bluetoothService.write(data.getBytes());
                            checkWinner();
                        }
                    }
                }
            }
        }
        processMessages();
        Gdx.gl.glClearColor(0.8f, 0.8f, 0.8f, 1);
        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);
        game.batch.begin();
        game.batch.draw(game.background, 0, 0);
        game.batch.end();
        game.batch.begin();
        fieldSprite.draw(game.batch);
        for(int column = 0; column < 3; ++ column) {
            for (int row = 0; row < 3; ++row) {
                if(field[column][row] != 0) {
                    Sprite sprite = field[column][row] == 1 ? xSprite : oSprite;
                    Rectangle rect = collisionRectangles[column][row];
                    sprite.setPosition(rect.x + rect.width / 2 - sprite.getWidth() / 2, rect.y + rect.height / 2 - sprite.getHeight() / 2);
                    sprite.draw(game.batch);
                }
            }
        }
        game.batch.end();
        stage.act();
        stage.draw();
    }

    @Override
    public void resize(int width, int height) {

    }

    @Override
    public void pause() {

    }

    @Override
    public void resume() {

    }

    @Override
    public void hide() {
        Gdx.app.log(Tag, "hiding");
        game.inputMultiplexer.clear();

        // make sure no old dialogs are shown when we come back
        dialog.remove();
    }

    @Override
    public void dispose() {

    }
}
