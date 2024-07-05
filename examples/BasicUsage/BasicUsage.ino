#include <Arduino.h>
#include "SimpleBLE.h"

#define SERVICE_UUID        "12345678-1234-5678-1234-56789abcdef0"
#define CHARACTERISTIC_UUID "12345678-1234-5678-1234-56789abcdef1"

SimpleBLE bleDevice("Theon", SERVICE_UUID, CHARACTERISTIC_UUID);

class MyCallbacks : public NimBLECharacteristicCallbacks {
    void onRead(NimBLECharacteristic* pCharacteristic) {
        Serial.println("Characteristic read request");
    }

    void onWrite(NimBLECharacteristic* pCharacteristic) {
        std::string value = pCharacteristic->getValue();
        String valueStr = String(value.c_str());
        Serial.println("Characteristic written: " + valueStr);

        if (valueStr == "forward") {
            Serial.println("Executing forward command");
        } else if (valueStr == "backward") {
            Serial.println("Executing backward command");
        } else if (valueStr == "left") {
            Serial.println("Executing left command");
        } else if (valueStr == "right") {
            Serial.println("Executing right command");
        }
    }
};

void setup() {
    Serial.begin(115200);
    Serial.println("Starting BLE work!");

    bleDevice.begin();
    bleDevice.setCallbacks(new MyCallbacks());
}

void loop() {
    delay(2000);
}
