#include "i2c_scanner.h"
#include "bmp280_interface.h"
#include "htu21d_interface.h"

#define LOOP_TIME 5000

bmp280_interface bmp_sensor;
htu21d_interface htu_sensor;

void setup()
{
  Serial.begin(115200);
  read_i2c(6, 1000);
  htu_sensor.setup_htu();
  bmp_sensor = bmp280_interface();
  bmp_sensor.setup_bmp(0x76);
}

void loop()
{
  // must call this to wake sensor up and get new measurement data
  // it blocks until measurement is complete
  htu_sensor.debug_serial();
  bmp_sensor.debug_serial(1018.15f);
  Serial.print(F("\nNew scan in "));
  Serial.print((float)LOOP_TIME / 1000.0f);
  Serial.println(F(" seconds"));
  delay(LOOP_TIME);
}