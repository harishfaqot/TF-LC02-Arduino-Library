#include "TF-LC02.h"

// Command to request distance measurement from TF-LC02
const uint8_t MEASURE_COMMAND[] = {0x55, 0xAA, 0x81, 0x00, 0xFA};

// Function to calculate distance from response
uint16_t parseDistance(uint8_t *data) {
  if (data[6] == 0x00) { // Valid data status
    return (data[4] << 8) | data[5]; // Combine MSB and LSB
  } else {
    return 0; // Invalid data
  }
}

// Initialize TF-LC02 sensor
void initTFLC02() {
  Serial1.begin(LIDAR_BAUDRATE); // TF-LC02 connected to Serial1
  Serial.println("TF-LC02 Test Initialized");
}

// Function to read distance from sensor
uint16_t getDistance() {
  uint8_t response[7];
  uint16_t distance = 0;

  // Send the measurement command
  Serial1.write(MEASURE_COMMAND, sizeof(MEASURE_COMMAND));

  // Wait for response
  if (Serial1.available() >= 7) { // Expected response length
    for (int i = 0; i <= 7; i++) {
      response[i] = Serial1.read();
    }

    // Validate packet header
    if (response[0] == 0x55 && response[1] == 0xAA) {
      // Distance calculation
      distance = parseDistance(response);
    }
  }
  
  return distance;
}
