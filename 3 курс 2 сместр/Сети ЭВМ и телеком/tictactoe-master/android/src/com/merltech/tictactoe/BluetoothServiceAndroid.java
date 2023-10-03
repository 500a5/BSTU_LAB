package com.merltech.tictactoe;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothServerSocket;
import android.bluetooth.BluetoothSocket;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.util.Log;

import com.merltech.tictactoe.network.BluetoothService;
import com.merltech.tictactoe.network.Message;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.UUID;

public class BluetoothServiceAndroid implements BluetoothService {
    //Debugging
    private static final String Tag = "BluetoothService";

    // Name for the SDP record when creating server socket
    private static final String ServiceName = "TicTacToeBluetoothService";

    // Unique UUID for this application
    private static final UUID BluetoothUUID = UUID.fromString("04c6093b-0000-1000-8000-00805f9b35fb");

    // Member fields
    private final BluetoothAdapter bluetoothAdapter;
    private AcceptThread acceptThread;
    private ConnectThread connectThread;
    private ConnectedThread connectedThread;

    // all queue operations should be synchronized using messageLock
    // unfortunately concurrent queues are only available in higher android api versions :/
    private Queue<Message> messageQueue;
    private final Object messageLock = new Object();

    // needed to ask for visibility etc.
    Context activityContext = null;

    // cache discovered devices so connections can be established by mac
    // when a new device is found a device found message is sent containing the name and mac
    // address of the device. When a connection should be established, the mac is provided
    // and the corresponding device is taken from this map
    private Map<String, BluetoothDevice> discoveredDevices = new HashMap<>();
    private String connectedMac = "";

    // context = UI Activity Context
    public BluetoothServiceAndroid(Context context) {
        activityContext = context;

        bluetoothAdapter = BluetoothAdapter.getDefaultAdapter();

        IntentFilter intentFilter = new IntentFilter();
        intentFilter.addAction(BluetoothAdapter.ACTION_DISCOVERY_FINISHED);
        intentFilter.addAction(BluetoothAdapter.ACTION_STATE_CHANGED);
        intentFilter.addAction(BluetoothDevice.ACTION_FOUND);
        activityContext.registerReceiver(broadcastReceiver, intentFilter);

        // create new messageQueue
        synchronized (messageLock) {
            messageQueue = new LinkedList<>();
        }

        activityContext = context;
    }

    @Override
    public synchronized boolean isAvailable() {
        return bluetoothAdapter != null;
    }

    @Override
    public synchronized boolean isEnabled() {
        if(!isAvailable()) {
            return false;
        }
        return bluetoothAdapter.isEnabled();
    }

    @Override
    public synchronized boolean isConnected() {
        return connectedThread != null || connectThread != null;
    }

    @Override
    public Message getMessage() {
        synchronized (messageLock) {
            return messageQueue.poll();
        }
    }

    @Override
    public void dispose() {
        cancelAll();
        activityContext.unregisterReceiver(broadcastReceiver);
    }

    @Override
    public synchronized void enable() {
        if(!isAvailable()) {
            return;
        }

        // only enable if not currently enabled or enabling
        if(bluetoothAdapter.getState() == BluetoothAdapter.STATE_TURNING_OFF || bluetoothAdapter.getState() == BluetoothAdapter.STATE_OFF) {
            bluetoothAdapter.enable();
        }
    }

    @Override
    public synchronized void disable() {
        if(!isAvailable()) {
            return;
        }

        // only disable if not currently disabled or disabling
        if(bluetoothAdapter.getState() == BluetoothAdapter.STATE_TURNING_ON || bluetoothAdapter.getState() == BluetoothAdapter.STATE_ON) {
            bluetoothAdapter.disable();
        }
    }

    @Override
    public void scan() {
        if(!isAvailable()) {
            return;
        }

        if(!bluetoothAdapter.isEnabled()) {
            Log.d(Tag , "scan() adapter is not enabled, can't scan");
            return;
        }

        // stop all threads (accepting, connecting, etc)
        cancelAll();

        // start discovering
        // from here the rest is handled in the broadcast receiver
        bluetoothAdapter.startDiscovery();
        // clear the cache
        discoveredDevices.clear();
    }


    @Override
    public void makeDiscoverable(int seconds) {
        // This has to be confirmed by the user -.-
        // the only workaround needs superuser permissions which is unacceptable for a game...
        Intent discoverableIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_DISCOVERABLE);
        // limit max duration to 300 seconds, that should be plenty we don't want to drain the battery
        // for unlimited discovery 0 can be passed as duration (NOT TESTED)
        seconds = Math.min(300, Math.max(0, seconds));
        discoverableIntent.putExtra(BluetoothAdapter.EXTRA_DISCOVERABLE_DURATION, seconds);
        activityContext.startActivity(discoverableIntent);
    }

    @Override
    public void setName(String name) {
        if(!isAvailable()) {
            return;
        }
        bluetoothAdapter.setName(name);
    }

    @Override
    public void connect(String macAddress) {
        if(!isAvailable()) {
            return;
        }

        BluetoothDevice connectDevice = discoveredDevices.get(macAddress);
        if(connectDevice != null) {
            connect(connectDevice);
        } else {
            Log.d(Tag, "connect() address: " + macAddress + " not present in cache, can't connect");
        }
    }

    @Override
    public void disconnect() {
        cancelAll();
    }

    @Override
    public synchronized void listen() {
        Log.d(Tag, "start");

        cancelAll();
        // Start the thread to listen on a BluetoothServerSocket
        if(acceptThread == null) {
            acceptThread = new AcceptThread();
            acceptThread.start();
        }
    }

    public synchronized void connect(BluetoothDevice device) {
        Log.d(Tag, "connect to: " + device);

        // cancel all threads doing something else
        cancelAll();

        // Start the thread to connect with the given device
        connectThread = new ConnectThread(device);
        connectThread.start();
    }

    public synchronized void connected(BluetoothSocket socket, BluetoothDevice device) {
        Log.d(Tag, "connected");

        cancelAll();
        // Start the thread to manage the connection and perform transmissions
        connectedThread = new ConnectedThread(socket);
        connectedThread.start();
    }

    public synchronized void stop() {
        Log.d(Tag, "stop");
        cancelAll();
    }

    // Write to the ConnectedThread in an unsynchronized manner
    public void write(byte[] out) {
        // Create a temporary object
        ConnectedThread tempThread = null;
        // Synchronize a copy of the ConnectedThread
        synchronized(this) {
            if(connectedThread != null) {
                tempThread = connectedThread;
            }
        }
        if(tempThread != null) {
            tempThread.write(out);
        }
    }

    // This thread runs while listening for incoming connections. It behaves
    // like a server-side client. It runs until a connection is accepted
    // (or until cancelled).
    private class AcceptThread extends Thread {
        // The local server socket
        private final BluetoothServerSocket bluetoothServerSocket;

        public AcceptThread() {
            BluetoothServerSocket tmp = null;

            // Create a new listening server socket
            try {
                tmp = bluetoothAdapter.listenUsingRfcommWithServiceRecord(ServiceName, BluetoothUUID);
            } catch (IOException e) {
                Log.e(Tag, "Error creating BluetoothServerSocket", e);
            }
            bluetoothServerSocket = tmp;
        }

        public void run() {
            Log.d(Tag, "AcceptThread started");
            BluetoothSocket socket = null;

            while(true) {
                try {
                    // This is a blocking call and will only return on a
                    // successful connection or an exception
                    socket = bluetoothServerSocket.accept();
                } catch (IOException e) {
                    Log.e(Tag, "Error accepting connection", e);
                    break;
                }

                // If a connection was accepted
                if(socket != null) {
                    synchronized(BluetoothServiceAndroid.this) {
                        connected(socket, socket.getRemoteDevice());

                        // we have a connection so we do no longer need to listen
                        break;
                    }
                }
            }
            Log.d(Tag, "AcceptThread ended");
        }

        public void cancel() {
            Log.d(Tag, "AcceptThread canceled");
            try {
                bluetoothServerSocket.close();
            } catch (IOException e) {
                Log.e(Tag, "Error closing ServerSocket", e);
            }
        }
    }

    // This thread runs while attempting to make an outgoing connection
    // with a device. It runs straight trough; the connection either succeds or fails
    private class ConnectThread extends Thread {
        private final BluetoothSocket bluetoothSocket;
        private final BluetoothDevice bluetoothDevice;

        public ConnectThread(BluetoothDevice device) {
            bluetoothDevice = device;
            BluetoothSocket tmp = null;

            // Get a BluetoothSocket for a connection with the given BluetoothDevice
            try {
                tmp = device.createRfcommSocketToServiceRecord(BluetoothUUID);
            } catch (IOException e) {
                Log.e(Tag, "Error creating BluetoothSocket", e);
            }
            bluetoothSocket = tmp;
        }

        public void run() {
            Log.i(Tag, "ConnectThread started");

            // Always cancel discovery because it will slow down a connection
            bluetoothAdapter.cancelDiscovery();

            // Make a connection to the BluetoothSocket
            try {
                // This is a blocking call and will only return on a
                // successful connection or an exception
                bluetoothSocket.connect();
            } catch (IOException e) {
                Log.e(Tag, "IOException", e);
                // close the socket
                try {
                    bluetoothSocket.close();
                } catch (IOException e2) {
                    Log.e(Tag, "Error closing socket after connection failure", e2);
                }
                sendMessage(new Message(Message.Code.BLUETOOTH_ERROR, 0, "connect failed"));
                return;
            }
            // Reset the ConnectThread because we're done
            synchronized (BluetoothServiceAndroid.this) {
                connectThread = null;
            }
            // Start the connected thread
            connected(bluetoothSocket, bluetoothDevice);
        }

        public void cancel() {
            try {
                bluetoothSocket.close();
            } catch (IOException e) {
                Log.e(Tag, "Error closing BluetoothSocket", e);
            }
        }
    }

    // This thread runs during a connection with a remote device.
    // It handles all incoming and outgoing transmissions
    private class ConnectedThread extends Thread {
        private final BluetoothSocket bluetoothSocket;
        private final InputStream inputStream;
        private final OutputStream outputStream;

        public ConnectedThread(BluetoothSocket socket) {
            Log.d(Tag, "create ConnectedThread");
            bluetoothSocket = socket;
            InputStream tmpInputStream = null;
            OutputStream tmpOutputStream =  null;

            try {
                tmpInputStream = socket.getInputStream();
                tmpOutputStream = socket.getOutputStream();
            } catch (IOException e) {
                Log.e(Tag, "Error creating I/O streams for socket", e);
            }
            inputStream = tmpInputStream;
            outputStream = tmpOutputStream;

            sendMessage(new Message(Message.Code.BLUETOOTH_CONNECTED, 0, null));
        }

        public void run() {
            Log.d(Tag, "ConnectedThread started");
            byte[] buffer = new byte[1024];
            int bytes;

            // Keep listening to the InputStream while connected
            while(true) {
                try {
                    // Read from the InputStream while connected
                    bytes = inputStream.read(buffer);

                    // create a new buffer for the message as the old one might be needed
                    // to receive before the message is handled
                    byte[] messageBuffer = Arrays.copyOf(buffer, bytes);

                    sendMessage(new Message(Message.Code.BLUETOOTH_RECEIVED, bytes, messageBuffer));
                 } catch (IOException e) {
                    Log.e(Tag, "disconnected", e);

                    sendMessage(new Message(Message.Code.BLUETOOTH_ERROR, 0, "connection was lost"));
                    break;
                }
            }
            Log.d(Tag, "ConnectedThread ended");
        }
        // Write to the connected OutputStream
        public void write(byte[] buffer) {
            try {
                outputStream.write(buffer);

                sendMessage(new Message(Message.Code.BLUETOOTH_SENT, buffer.length, buffer));
            } catch (IOException e) {
                Log.e(Tag, "Exception during write", e);
            }
        }

        public void cancel() {
            try {
                bluetoothSocket.close();
            } catch (IOException e) {
                Log.e(Tag, "Error closing Bluetooth Socket", e);
            }
        }
    }

    private void sendMessage(Message message) {
        synchronized(messageLock) {
            messageQueue.add(message);
        }
    }

    // receives android system messages (adapter changend) etc.
    private BroadcastReceiver broadcastReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            String action = intent.getAction();

            if (BluetoothDevice.ACTION_FOUND.equals(action)) {
                // We found a device
                BluetoothDevice device = intent.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE);
                Log.d(Tag, "found device: " + device.getName() + " / " + device.getAddress());
                discoveredDevices.put(device.getAddress() ,device);

                // we need to send the device as message
                sendMessage(new Message(Message.Code.BLUETOOTH_DEVICE_FOUND, 0, new BluetoothPeer(device.getName(), device.getAddress())));
            } else if (BluetoothAdapter.ACTION_DISCOVERY_FINISHED.equals(action)) {
                Log.d(Tag, "discovery finished");
                sendMessage(new Message(Message.Code.BLUETOOTH_DISCOVERY_FINISHED, 0, null));
            } else if (BluetoothAdapter.ACTION_STATE_CHANGED.equals(action)) {
                int adapterState = intent.getIntExtra(BluetoothAdapter.EXTRA_STATE, BluetoothAdapter.ERROR);
                int adapterStatePrevious = intent.getIntExtra(BluetoothAdapter.EXTRA_PREVIOUS_STATE, BluetoothAdapter.ERROR);

                // ugly shit right here
                Map<Integer, String> mapping = new HashMap<>();
                mapping.put(BluetoothAdapter.STATE_OFF, "Off");
                mapping.put(BluetoothAdapter.STATE_TURNING_ON, "TurningOn");
                mapping.put(BluetoothAdapter.STATE_ON, "On");
                mapping.put(BluetoothAdapter.STATE_TURNING_OFF, "TurningOff");

                Log.d(Tag, "adapter changed state: " + mapping.get(adapterStatePrevious) + " -> " + mapping.get(adapterState));
                switch(adapterState) {
                    case BluetoothAdapter.STATE_OFF:
                        sendMessage(new Message(Message.Code.BLUETOOTH_ADAPTER_DISABLED, 0, null));
                        break;
                    case BluetoothAdapter.STATE_ON:
                        sendMessage(new Message(Message.Code.BLUETOOTH_ADAPTER_ENABLED, 0, null));
                        break;
                    case BluetoothAdapter.STATE_TURNING_OFF:
                        break;
                    case BluetoothAdapter.STATE_TURNING_ON:
                        break;
                    default:
                        break;
                }
            }
        }
    };

    // stops whatever the adapter is doing at the moment
    private synchronized void cancelAll() {
        // if we are currently in discovery mode, disable
        if(bluetoothAdapter.isDiscovering()) {
            bluetoothAdapter.cancelDiscovery();
        }
        // Cancel any thread attempting to make a connection
        if (connectThread != null) {
            connectThread.cancel();
            connectThread = null;
        }

        // Cancel any thread currently running a connection
        if (connectedThread != null) {
            connectedThread.cancel();
            connectedThread = null;
        }

        // if we are currently accepting stop it
        if (acceptThread != null) {
            acceptThread.cancel();
            acceptThread = null;
        }
    }
}

