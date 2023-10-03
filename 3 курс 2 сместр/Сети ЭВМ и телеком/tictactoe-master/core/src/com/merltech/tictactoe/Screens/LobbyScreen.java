package com.merltech.tictactoe.Screens;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Input;
import com.badlogic.gdx.Screen;
import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.TextureRegion;
import com.badlogic.gdx.scenes.scene2d.InputEvent;
import com.badlogic.gdx.scenes.scene2d.Stage;
import com.badlogic.gdx.scenes.scene2d.ui.Dialog;
import com.badlogic.gdx.scenes.scene2d.ui.ImageButton;
import com.badlogic.gdx.scenes.scene2d.ui.Label;
import com.badlogic.gdx.scenes.scene2d.ui.Skin;
import com.badlogic.gdx.scenes.scene2d.ui.Table;
import com.badlogic.gdx.scenes.scene2d.ui.TextButton;
import com.badlogic.gdx.scenes.scene2d.ui.Value;
import com.badlogic.gdx.scenes.scene2d.utils.ClickListener;
import com.badlogic.gdx.scenes.scene2d.utils.Drawable;
import com.badlogic.gdx.scenes.scene2d.utils.TextureRegionDrawable;
import com.badlogic.gdx.utils.viewport.ScreenViewport;
import com.merltech.tictactoe.TicTacToe;
import com.merltech.tictactoe.network.BluetoothService;
import com.merltech.tictactoe.network.Message;

public class LobbyScreen implements Screen {
    private final TicTacToe game;
    private final BluetoothService bluetoothService;
    private Skin skin;
    private Stage stage;
    float runningTime = 0;

    // UI
    private Table peerTable;
    private Dialog noBluetoothDialog;
    private ImageButton bluetoothButton;
    private Label connectLabel;
    private Label nameLabel;
    boolean animateBluetooth = false;

    private final String Tag = "Lobby";

    public LobbyScreen(TicTacToe game) {
        this.game = game;
        this.skin = game.skin;
        this.bluetoothService = game.bluetoothService;

        setupUi();
    }

    private void setupUi() {
        stage = new Stage(new ScreenViewport());

        Texture bluetoothIcon = new Texture(Gdx.files.local("bluetooth.png"));
        Drawable drawable = new TextureRegionDrawable(new TextureRegion(bluetoothIcon));
        bluetoothButton = new ImageButton(drawable);

        noBluetoothDialog = new Dialog("No Bluetooth", skin) {
            protected void result(Object object) {

            };
        };
        Label enableBluetooth = new Label("Please enable bluetooth first", skin);
        noBluetoothDialog.text(enableBluetooth);
        noBluetoothDialog.button("Okay").center();
        noBluetoothDialog.setMovable(false);

        // default style
        TextButton.TextButtonStyle style = new TextButton("a", skin).getStyle();
        style.font = skin.getFont("small-font");
        final TextButton scanButton = new TextButton("Scan", style);
        scanButton.getLabel().setColor(Color.BLACK);
        final TextButton hostButton = new TextButton("Host", style);
        hostButton.getLabel().setColor(Color.BLACK);

        hostButton.addListener(new ClickListener(){
            @Override
            public void clicked(InputEvent event, float x, float y) {
                if(!bluetoothService.isEnabled()) {
                    noBluetoothDialog.show(stage);
                } else {
                    bluetoothService.makeDiscoverable(30);
                    game.setScreen(game.gameScreen);
                }
            }
        });

        scanButton.addListener(new ClickListener(){
            @Override
            public void clicked(InputEvent event, float x, float y) {
                if(!bluetoothService.isEnabled()) {
                    noBluetoothDialog.show(stage);
                } else {
                    bluetoothService.scan();
                    peerTable.clear();
                    peerTable.add(nameLabel).left().expandX();
                    peerTable.add(connectLabel).right();
                }
            }
        });

        bluetoothButton.addListener(new ClickListener(){
            @Override
            public void clicked(InputEvent event, float x, float y) {
                if(bluetoothService.isEnabled()) {
                    bluetoothService.disable();
                    // starts at running time = PI/4
                    runningTime = (float)Math.PI / 4;
                } else {
                    bluetoothService.enable();
                    runningTime = 0.0f;
                }
                animateBluetooth = true;
            }
        });

        Table rootTable = new Table(skin);
        rootTable.setFillParent(true);

        Label titleLabel = new Label("Tic Tac Toe", skin, "big-font", Color.BLACK);
        rootTable.add(titleLabel).center().expandX();

        rootTable.row().expandY().top();
        peerTable = new Table(skin);
        nameLabel = new Label("Name", skin, "small-font", Color.BLACK);
        peerTable.add(nameLabel).left().expandX();
        connectLabel = new Label("Connect", skin, "small-font", Color.BLACK);
        peerTable.add(connectLabel).right();
        peerTable.pad(Value.zero, Value.percentWidth(0.03f, rootTable), Value.zero, Value.percentWidth(0.03f, rootTable));
        rootTable.add(peerTable).fillX();

        rootTable.row().bottom();
        Table buttonTable = new Table(skin);
        buttonTable.add(scanButton).center().expandX();
        buttonTable.add(hostButton).center().expandX();
        buttonTable.add(bluetoothButton).center().expandX();
        rootTable.add(buttonTable).fillX();

        stage.addActor(rootTable);
    }

    private void processMessages() {
        Message message = null;
        while((message = bluetoothService.getMessage()) != null) {
            Gdx.app.log(Tag, "received message: " + message.code.name());
            switch(message.code) {
                case BLUETOOTH_ADAPTER_ENABLED:
                    Gdx.app.log(Tag, "bluetooth enabled");
                    animateBluetooth = false;
                    bluetoothButton.getImage().setColor(1.0f, 1.0f, 1.0f, 1.0f);
                    break;
                case BLUETOOTH_ADAPTER_DISABLED:
                    Gdx.app.log(Tag, "bluetooth disabled");
                    animateBluetooth = false;
                    bluetoothButton.getImage().setColor(0.3f, 0.3f, 0.3f, 1.0f);
                    break;
                case BLUETOOTH_CONNECTED:
                    Gdx.app.log(Tag, "bluetooth connected");
                    game.setScreen(game.gameScreen);
                    break;
                case BLUETOOTH_DEVICE_FOUND:
                    Gdx.app.log(Tag, "bluetooth device found");
                    addPeer((BluetoothService.BluetoothPeer)message.data);
                    break;
                case BLUETOOTH_ERROR:
                    Gdx.app.log(Tag, "ERROR: " + message.data);
                default:
                    Gdx.app.log(Tag, "message not handled, discarded");
            }
        }
    }

    private void addPeer(BluetoothService.BluetoothPeer peer) {
        Texture background = new Texture(Gdx.files.local("connect.png"));
        Drawable drawable = new TextureRegionDrawable(new TextureRegion(background));

        ImageButton.ImageButtonStyle imageButtonStyle = new ImageButton.ImageButtonStyle();
        TextButton.TextButtonStyle textButtonStyle = new TextButton("a", skin).getStyle();
        imageButtonStyle.up = textButtonStyle.up;
        imageButtonStyle.down = textButtonStyle.down;
        imageButtonStyle.checked = textButtonStyle.checked;
        imageButtonStyle.imageUp = drawable;
        imageButtonStyle.imageDown = drawable;
        imageButtonStyle.imageChecked = drawable;


        peerTable.row().pad(Value.percentWidth(0.01f, peerTable), Value.zero, Value.percentWidth(0.01f, peerTable), Value.zero);
        String name = peer.Name;
        Label label = new Label(name, skin, "small-font", Color.BLACK);

        // I am a lazy fuck...
        for(int n = name.length(); label.getWidth() > peerTable.getWidth() * 0.65f; --n) {
            if(n == 0) {
                break;
            }
            name = peer.Name.substring(0, n - 1) + "...";
            label = new Label(name, skin, "small-font", Color.BLACK);
        }

        peerTable.add(label).left().pad(Value.zero, Value.percentWidth(0.01f, peerTable), Value.zero, Value.zero);
        // The address makes everything to large
        //peerTable.add(peer.Address);
        final ImageButton connectButton = new ImageButton(imageButtonStyle);
        final String buttonAddress = peer.Address;
        connectButton.addListener(new ClickListener(){
            @Override
            public void clicked(InputEvent event, float x, float y) {
                Gdx.app.log(Tag, "connecting to: " + buttonAddress);
                bluetoothService.connect(buttonAddress);
            }
        });
        peerTable.add(connectButton).center();
    }

    @Override
    public void show() {
        Gdx.app.log(Tag, "showing");
        game.inputMultiplexer.addProcessor(stage);
        float brightness = bluetoothService.isEnabled() ? 1.0f : 0.3f;
        animateBluetooth = false;
        bluetoothButton.getImage().setColor(brightness, brightness, brightness, 1.0f);
    }

    @Override
    public void render(float delta) {
        if(Gdx.input.isKeyJustPressed(Input.Keys.BACK)) {
            // back key was pressed in lobby -> exit application
            Gdx.app.exit();
        }
        runningTime += Math.min(0.03f, Gdx.graphics.getDeltaTime());
        if(animateBluetooth) {
            float brightness = (float)(Math.sin(runningTime*4)+1) / 2 * 0.7f + 0.3f;
            bluetoothButton.getImage().setColor(brightness, brightness, brightness, 1.0f);
        }
        processMessages();

        Gdx.gl.glClearColor(0.8f, 0.8f, 0.8f, 1);
        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);
        game.batch.begin();
        game.batch.draw(game.background, 0, 0);
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

    }

    @Override
    public void dispose() {

    }
}
