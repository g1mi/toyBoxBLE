#ifndef SIMPLE_BLE_H
#define SIMPLE_BLE_H

#include <NimBLEDevice.h>

// The SimpleBLE class encapsulates the basic operations for BLE, simplifying BLE initialization and usage.
class SimpleBLE {
public:
    // Constructor: Initializes the device name, service UUID, and characteristic UUID.
    SimpleBLE(const char* deviceName, const char* serviceUUID, const char* characteristicUUID);

    // Initializes the BLE device and starts advertising.
    void begin();

    // Sets the callbacks for the characteristic.
    void setCallbacks(NimBLECharacteristicCallbacks* callbacks);

    // Sends a notification to the connected client.
    void notify(const std::string& value);

private:
    const char* deviceName;  // The name of the BLE device.
    const char* serviceUUID;  // The UUID of the BLE service.
    const char* characteristicUUID;  // The UUID of the BLE characteristic.

    NimBLEServer* pServer;  // The BLE server instance.
    NimBLEService* pService;  // The BLE service instance.
    NimBLECharacteristic* pCharacteristic;  // The BLE characteristic instance.

    // Internal class to handle server callbacks for connection and disconnection events.
    class ServerCallbacks : public NimBLEServerCallbacks {
        void onConnect(NimBLEServer* pServer);  // Called when a client connects.
        void onDisconnect(NimBLEServer* pServer);  // Called when a client disconnects.
    };
};

#endif
