package com.merltech.tictactoe.network;

public interface BluetoothService {
    public boolean isAvailable();
    public boolean isEnabled();
    public boolean isConnected();
    public Message getMessage();
    public void dispose();
    public void enable();
    public void disable();
    public void scan();
    public void makeDiscoverable(int seconds);
    public void setName(String name);
    public void connect(String macAddress);
    public void disconnect();
    public void listen();
    public void write(byte[] buffer);

    public class BluetoothPeer {
        public final String Name;
        public final String Address;

        public BluetoothPeer(final String name, final String address) {
            Name = name;
            Address = address;
        }
    }
}
