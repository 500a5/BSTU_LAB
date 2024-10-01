package com.merltech.tictactoe;

import com.badlogic.gdx.Game;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.InputMultiplexer;
import com.badlogic.gdx.files.FileHandle;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.BitmapFont;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.graphics.g2d.TextureAtlas;
import com.badlogic.gdx.graphics.g2d.freetype.FreeTypeFontGenerator;
import com.badlogic.gdx.scenes.scene2d.ui.Skin;
import com.merltech.tictactoe.Screens.GameScreen;
import com.merltech.tictactoe.Screens.LobbyScreen;
import com.merltech.tictactoe.graphics.SVGService;
import com.merltech.tictactoe.network.BluetoothService;


import java.io.InputStream;
import java.io.OutputStream;

public class TicTacToe extends Game {
    private SVGService svgService;
    private final float density;
    public SpriteBatch batch;
	public Skin skin;
    public Texture background;
    public InputMultiplexer inputMultiplexer;
    public BluetoothService bluetoothService;

    public LobbyScreen lobbyScreen;
    public GameScreen gameScreen;

    private final String Tag = "TicTacToe";

    public TicTacToe(BluetoothService bluetoothService, SVGService svgService, float density) {
        this.bluetoothService = bluetoothService;
        this.svgService = svgService;
        this.density = density;
    }

	@Override
	public void create () {
        this.batch = new SpriteBatch();

        generateGraphics();
        generateFonts();

        background = new Texture(Gdx.files.local("background.png"));

        inputMultiplexer = new InputMultiplexer();
		Gdx.input.setInputProcessor(inputMultiplexer);
        Gdx.input.setCatchBackKey(true);

        // create screens
        lobbyScreen = new LobbyScreen(this);
        gameScreen = new GameScreen(this);

        this.setScreen(lobbyScreen);
	}

    private void generateGraphics() {
        InputStream inputStream;
        OutputStream outputStream;
        if(!Gdx.files.local("bluetooth.png").exists()) {
            inputStream = Gdx.files.internal("ui/bluetooth.svg").read();
            outputStream = Gdx.files.local("bluetooth.png").write(false);
            svgService.scaleToDPI(inputStream, outputStream);
        }
        if(!Gdx.files.local("connect.png").exists()) {
            inputStream = Gdx.files.internal("ui/connect.svg").read();
            outputStream = Gdx.files.local("connect.png").write(false);
            svgService.scaleToDPI(inputStream, outputStream);
        }
        if(!Gdx.files.local("background.png").exists()) {
            inputStream = Gdx.files.internal("ui/background.svg").read();
            outputStream = Gdx.files.local("background.png").write(false);
            svgService.fill(inputStream, outputStream, Gdx.graphics.getWidth(), Gdx.graphics.getHeight());
        }
        if(!Gdx.files.local("field.png").exists()) {
            inputStream = Gdx.files.internal("ui/field.svg").read();
            outputStream = Gdx.files.local("field.png").write(false);
            svgService.fit(inputStream, outputStream, Gdx.graphics.getWidth(), Gdx.graphics.getHeight());
        }
        if(!Gdx.files.local("X.png").exists()) {
            inputStream = Gdx.files.internal("ui/X.svg").read();
            outputStream = Gdx.files.local("X.png").write(false);
            svgService.scaleToDPI(inputStream, outputStream);
        }
        if(!Gdx.files.local("O.png").exists()) {
            inputStream = Gdx.files.internal("ui/O.svg").read();
            outputStream = Gdx.files.local("O.png").write(false);
            svgService.scaleToDPI(inputStream, outputStream);
        }
    }

    private void generateFonts() {
        FreeTypeFontGenerator orangeJuiceGenerator = new FreeTypeFontGenerator(Gdx.files.internal("ui/orangejuice.ttf"));
        FreeTypeFontGenerator unispaceGenerator = new FreeTypeFontGenerator(Gdx.files.internal("ui/unispace.ttf"));
        FreeTypeFontGenerator.FreeTypeFontParameter parameter = new FreeTypeFontGenerator.FreeTypeFontParameter();

        // this has to be related to density on screen
        parameter.size = (int)(density / 14);
        BitmapFont defaultFont = unispaceGenerator.generateFont(parameter);
        parameter.size = (int)(density / 6);
        BitmapFont smallFont = orangeJuiceGenerator.generateFont(parameter);
        parameter.size = (int)(density / 4);
        BitmapFont bigFont = orangeJuiceGenerator.generateFont(parameter);

        skin = new Skin();
        skin.add("default-font", defaultFont, BitmapFont.class);
        skin.add("small-font", smallFont, BitmapFont.class);
        skin.add("big-font", bigFont, BitmapFont.class);
        FileHandle fileHandle = Gdx.files.internal("ui/uiskin.json");
        FileHandle atlasFile = Gdx.files.internal("ui/uiskin.atlas");
        if(atlasFile.exists()) {
            skin.addRegions(new TextureAtlas(atlasFile));
        }
        skin.load(fileHandle);
        orangeJuiceGenerator.dispose();
        unispaceGenerator.dispose();
    }

    @Override
	public void render () {
        super.render();
	}


    @Override
	public void dispose () {
        bluetoothService.dispose();
	}
}
