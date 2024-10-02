package com.merltech.tictactoe;

import android.os.Bundle;

import com.badlogic.gdx.backends.android.AndroidApplication;
import com.badlogic.gdx.backends.android.AndroidApplicationConfiguration;

public class AndroidLauncher extends AndroidApplication {
	@Override
	protected void onCreate (Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		AndroidApplicationConfiguration config = new AndroidApplicationConfiguration();
		initialize(new TicTacToe(new BluetoothServiceAndroid(this), new SVGServiceAndroid(getResources().getDisplayMetrics().xdpi), getResources().getDisplayMetrics().xdpi), config);
	}
}
