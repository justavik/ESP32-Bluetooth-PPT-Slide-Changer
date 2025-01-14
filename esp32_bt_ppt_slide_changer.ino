/**
 * @file slide_controller.ino
 * @brief Bluetooth LE keyboard controller for presentation slides
 * 
 * This device emulates a keyboard over BLE, sending up/down arrow key events
 * based on button presses. Includes hardware debouncing for reliable operation.
 */

#include <BleKeyboard.h>

// initializing BLE keyboard with device name
BleKeyboard bleKeyboard("Slide Controller");

// GPIO pin definitions
const int upButtonPin = 13;
const int downButtonPin = 12;

// button state tracking
bool upButtonPressed = false;
bool downButtonPressed = false;

// debouncing
unsigned long lastUpDebounceTime = 0;
unsigned long lastDownDebounceTime = 0;
const unsigned long debounceDelay = 250;  // ms between allowed button presses

void setup() {
    pinMode(upButtonPin, INPUT_PULLDOWN);
    pinMode(downButtonPin, INPUT_PULLDOWN);
    
    bleKeyboard.begin();
}

void loop() {
    if(bleKeyboard.isConnected()) {
        unsigned long currentTime = millis();
        
        // processing up button
        if(digitalRead(upButtonPin) == HIGH) {
            if(!upButtonPressed && (currentTime - lastUpDebounceTime) > debounceDelay) {
                bleKeyboard.write(KEY_UP_ARROW);
                upButtonPressed = true;
                lastUpDebounceTime = currentTime;
            }
        } else {
            upButtonPressed = false;
        }
        
        // processing down button
        if(digitalRead(downButtonPin) == HIGH) {
            if(!downButtonPressed && (currentTime - lastDownDebounceTime) > debounceDelay) {
                bleKeyboard.write(KEY_DOWN_ARROW);
                downButtonPressed = true;
                lastDownDebounceTime = currentTime;
            }
        } else {
            downButtonPressed = false;
        }
    }
}
