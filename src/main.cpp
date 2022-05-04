#include "i2c_scanner.h"
#include "bmp280_interface.h"

bmp280_interface bmp_sensor;

void setup() {
  Serial.begin(9600);
  read_i2c(3, 2500);
  Serial.println(F("BMP280 Forced Mode Test."));
  bmp_sensor = bmp280_interface();
  bmp_sensor.setup_bmp(0x76);
  //if (!bmp.begin(BMP280_ADDRESS_ALT, BMP280_CHIPID)) {

}



void loop() {
  // must call this to wake sensor up and get new measurement data
  // it blocks until measurement is complete

  bmp_sensor.debug_serial();
  Serial.println(F("New record in 5 seconds"));
  delay(5000);


}