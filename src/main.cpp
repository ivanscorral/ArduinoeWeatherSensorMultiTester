#include "bmp280_interface.h"

//Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
//Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);

bmp280_interface bmp_sensor;
void setup() {
  Serial.begin(9600);
  Serial.println(F("BMP280 Forced Mode Test."));
  bmp_sensor = bmp280_interface();
  bmp_sensor.setup_bmp(0x76);
  //if (!bmp.begin(BMP280_ADDRESS_ALT, BMP280_CHIPID)) {

}



void loop() {
  // must call this to wake sensor up and get new measurement data
  // it blocks until measurement is complete


  Serial.println("New record in 5 seconds");
  delay(5000)


}