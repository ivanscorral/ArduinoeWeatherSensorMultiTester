#ifndef I2C_SCANNER_H
#define I2C_SCANNER_H

#include "Arduino.h"
#include <Wire.h>

void scan_i2c();
void read_i2c(uint8_t iterations);

#endif // !I2C_SCANNER_H
