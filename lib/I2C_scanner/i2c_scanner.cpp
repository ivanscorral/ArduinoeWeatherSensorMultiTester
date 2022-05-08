#include "i2c_scanner.h"

void setup_wire(bool first_iteration)
{
  if (first_iteration)
  {
    Wire.begin();
    while (!Serial)
      delay(1);
  }
  else
    return;
}
void read_i2c(uint8_t iterations, long delayMs)
{
  uint8_t i = 0;
  setup_wire(!i);
  for (i = 0; i < iterations; i++)
  {
    Serial.print(F("I2C scan running for "));
    Serial.print(iterations - i);
    Serial.print(F(" times, delay is "));
    Serial.print((float)delayMs / 1000.0f);
    Serial.println(F(" seconds."));
    scan_i2c();
    delay(delayMs);
  }
}

void scan_i2c()
{
  byte error, address;
  uint8_t nDevices;

  nDevices = 0;
  for (address = 1; address < 127; address++)
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print(F("I2C device found at address 0x"));
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println("  !");

      nDevices++;
    }
    else if (error == 4)
    {
      Serial.print(F("Unknown error at address 0x"));
      if (address < 16)
        Serial.print(0);
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0)
    Serial.println(F("No I2C devices found\n"));
}