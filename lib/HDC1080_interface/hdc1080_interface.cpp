#include "hdc1080_interface.h"

hdc1080_interface::hdc1080_interface() {}
hdc1080_interface::~hdc1080_interface() {}

void hdc1080_interface::setup_sensor()
{
	Serial.println("HDC1080 Init");

	hdc.begin(hdc1080_addr);

	Serial.print("Manufacturer ID=0x");
	Serial.println(hdc.readManufacturerId(), HEX);
	Serial.print("Device ID=0x");
	Serial.println(hdc.readDeviceId(), HEX);
}

void hdc1080_interface::debug_sensor()
{
  sensor_data data = read_sensor();
  Serial.print(F("\n{sensor: 'hdc1080' { temperature: '"));
  Serial.print(data.temperature, 2);
  Serial.print(F(" ºC' , pressure: '"));
  Serial.print(data.pressure_hPa);
  Serial.print(F(" hPa', altitudea: '"));
  Serial.print(data.altitude);
  Serial.println(F(" m'}} "));
}
sensor_data hdc1080_interface::read_sensor()
{
  sensor_data result;
  result.temperature = hdc.readTemperature();
  delay(25);
  result.humidity = hdc.readHumidity();
  return result;
}