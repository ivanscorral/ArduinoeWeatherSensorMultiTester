#include "i2c_scanner.h"
#include "bmp280_interface.h"
#include "htu21d_interface.h"

bmp280_interface bmp_sensor;
htu21d_interface htu_sensor;


void setup() {
  Serial.begin(115200);
  read_i2c(3, 1500);
  htu_sensor.setup_htu();
  htu_sensor.read_htu(0,0);
  Serial.println(F("BMP280 Forced Mode Test."));
  bmp_sensor = bmp280_interface();
  bmp_sensor.setup_bmp(0x76);
  //if (!bmp.begin(BMP280_ADDRESS_ALT, BMP280_CHIPID)) {

}



void loop() {
  // must call this to wake sensor up and get new measurement data
  // it blocks until measurement is complete
  htu_sensor.read_htu(0,0);
  bmp_sensor.debug_serial();
  Serial.println(F("\nNew record in 5 seconds"));
  delay(5000);


}