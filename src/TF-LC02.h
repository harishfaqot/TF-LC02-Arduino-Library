#ifndef TF_LC02_H
#define TF_LC02_H

#include <Arduino.h>

// Baud rate for TF-LC02 sensor communication
#define LIDAR_BAUDRATE 115200

// Command to request distance measurement from TF-LC02
extern const uint8_t MEASURE_COMMAND[];

// Function to calculate distance from sensor response
uint16_t parseDistance(uint8_t *data);

// Function to initialize the sensor
void initTFLC02();

// Function to read distance from sensor
uint16_t getDistance();

#endif // TF_LC02_H
