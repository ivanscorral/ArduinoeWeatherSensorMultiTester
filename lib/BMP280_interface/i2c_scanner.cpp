#include "i2c_scanner.h"

void read_i2c(uint8_t iterations){
    Wire.begin();
    while(!Serial)
    delay(10);
    Serial.print("I2C SCAN RUNNING FOR ");
    Serial.print(iterations);
    Serial.println(" TIMES.");
    for (uint16_t i = 0; i < iterations; i++)
    {
        scan_i2c();
        delay(3000);
    }
    
}

void scan_i2c(){
      byte error, address;
  int nDevices;
 
  Serial.println("Scanning...");
 
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
 
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");
 
      nDevices++;
    }
    else if (error==4)
    {
      Serial.print("Unknown error at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");
 
}