package com.merltech.tictactoe.network;

// Message class used for BluetoothService and (soon) WiFiService to communicate with the GameThread

public class Message {

    public static enum Code {
        BLUETOOTH_DEVICE_FOUND,
        BLUETOOTH_DISCOVERY_FINISHED,
        BLUETOOTH_ADAPTER_ENABLED,
        BLUETOOTH_ADAPTER_DISABLED,
        BLUETOOTH_CONNECTED,
        BLUETOOTH_DISCONNECTED,
        BLUETOOTH_RECEIVED,
        BLUETOOTH_SENT,
        BLUETOOTH_ERROR
    }

    public final Code code;
    public final int arg2;
    public final Object data;

    public Message(Code code, int arg2, Object data) {
        this.code = code;
        this.arg2 = arg2;
        this.data = data;
    }
}
