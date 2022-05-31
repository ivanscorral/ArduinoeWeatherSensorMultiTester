#include "aht20_interface.h"

aht_interface::aht_interface(){
}
aht_interface::~aht_interface(){
}
void aht_interface::setup_sensor()
{
	Serial.println("AHT20 demo!");

    if (! aht.begin()) {
        Serial.println("Could not find AHT20? Check wiring");
        while (1) delay(10);
    }
  Serial.println("AHT20 found");
}

void aht_interface::debug_sensor()
{
  sensor_data data = read_sensor();

  Serial.printf("AHT20: Temperature: %.2f degrees C, ",fata.temperature);
  Serial.printf("Humidity: %.2f \% rH\n", data.humidity);
}
sensor_data aht_interface::read_sensor()
{
  sensor_data result;
sensors_event_t humidity, temp;
   aht.getEvent(&humidity, &temp)
  result.temperature = temp.temperature;
  delay(25);
  result.humidity = humidity.relative_humidity;
  return result;
}