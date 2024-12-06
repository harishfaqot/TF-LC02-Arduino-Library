#include <TF-LC02.h>

// Ensure your wiring is correct as expected below
// TF-LC02                     Arduino (Use Serial 1) 
// 3v3, GND, RX, TX, CS        3v3, GND, TX, RX, GND
// CS pin must be wired to GND to enable serial output

void setup() {
  Serial.begin(9600);  // Initialize Serial Monitor at 9600 baud rate
  initTFLC02();        // Initialize the TF-LC02 sensor via Serial1
}

void loop() {
  uint16_t distance = getDistance();  // Get the distance from the sensor
  Serial.print("Distance: ");
  Serial.print(distance);            // Print the distance
  Serial.println(" mm");             // Print "mm" as unit

  delay(100);  // Delay for 100ms between measurements
}