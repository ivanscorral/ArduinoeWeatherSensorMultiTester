#include "htu21d_interface.h"

htu21d_interface::htu21d_interface()
{
  htu = Adafruit_HTU21DF();
}

void htu21d_interface::setup_sensor()
{
  if (!htu.begin() || !Serial)
  {
    Serial.println(F("Couldn't find sensor!"));
    while (1)
      ;
  }
}
void htu21d_interface::debug_sensor()
{
  sensor_data data = read_sensor();
  Serial.print(F("\n{sensor: 'htu21d' { temperature: '"));
  Serial.print(data.temperature, 2);
  Serial.print(F(" ºC', humidity: '"));
  Serial.print(data.humidity);
  Serial.println(F(" %'}} "));
}

sensor_data htu21d_interface::read_sensor()
{
  sensor_data result;
  result.temperature = htu.readTemperature();
  result.humidity = htu.readHumidity();
  return result;
}
