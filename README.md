# TF-LC02 Arduino Library

This is an Arduino library for interfacing with the **TF-LC02** distance sensor. The library provides simple functions to request distance measurements and parse the response from the sensor.

## Features
- Initialize the TF-LC02 sensor.
- Request and retrieve distance measurements.
- Easy integration into Arduino projects.

## Installation

1. Download or clone this repository to your local machine.
2. Move the `TF-LC02` folder to your Arduino libraries directory:
   - On Windows: `Documents/Arduino/libraries/`
   - On macOS/Linux: `~/Documents/Arduino/libraries/`
3. Restart the Arduino IDE to load the library.

Alternatively, you can install the library through the Arduino Library Manager by submitting it to the manager (see [Submit to Library Manager](https://arduino.github.io/arduino-cli/library-specification/)).

## Usage Example

Here is an example sketch to get started with the TF-LC02 sensor:

```cpp
#include <TF-LC02.h>

void setup() {
  initTFLC02(); // Initialize the sensor
}

void loop() {
  uint16_t distance = getDistance(); // Get distance from the sensor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" mm");

  delay(100); // Delay between measurements
}
