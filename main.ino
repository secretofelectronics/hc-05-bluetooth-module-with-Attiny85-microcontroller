#include <SoftwareSerial.h>

#define LED_PIN 0  // PB0 (Pin 5 of ATtiny85)
#define BT_RX 3    // PB3 (Pin 2 of ATtiny85)
#define BT_TX 4    // PB4 (Pin 3 of ATtiny85)

// Initialize SoftwareSerial
SoftwareSerial BTSerial(BT_RX, BT_TX);

void setup() {
    pinMode(LED_PIN, OUTPUT);
    BTSerial.begin(9600);  // HC-05 default baud rate
}

void loop() {
    if (BTSerial.available()) {
        char data = BTSerial.read();  // Read data from Bluetooth module

        if (data == '1') {
            digitalWrite(LED_PIN, HIGH);  // Turn LED ON
        } 
        else if (data == '0') {
            digitalWrite(LED_PIN, LOW);  // Turn LED OFF
        }
    }
}
