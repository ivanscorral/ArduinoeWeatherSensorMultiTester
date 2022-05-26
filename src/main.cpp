#include "i2c_scanner.h"
#include "bmp280_interface.h"
#include "htu21d_interface.h"
#include "sht31_interface.h"

float seconds_since_active = 0;
float boot_time;
uint16_t loops = 0;

bmp280_interface bmp_sensor;
htu21d_interface htu_sensor;
sht31_interface sht_sensor = sht31_interface();

void setup()
{

  boot_time = millis() / 1000.0f;
  Serial.begin(115200);
  read_i2c(3, 1500);

  htu_sensor.setup_sensor();
  bmp_sensor.setup_sensor(BMP280_ADDRESS_ALT);
  sht_sensor.setup_sensor();
}

void loop()
{
  sht_sensor.debug_sensor();
  htu_sensor.debug_sensor();
  bmp_sensor.debug_sensor();

  uint16_t loop_delay = random(5, 15) * 1000;

  if (seconds_since_active == 0)
    seconds_since_active = (float)(millis() - boot_time) / 1000.0f;
  else
    seconds_since_active += (float)(loop_delay / 1000.0f);

  if ((loops == 0) || (loops % 5 == 0) )
  {
    Serial.print("\n\t----- ");
    Serial.print(seconds_since_active);
    Serial.print(" seconds since boot.");
    Serial.println(" -----\t");
  }
  delay(loop_delay);
    loops++;

}