#include "htu21d_interface.h"

htu21d_interface::htu21d_interface()
{
  htu = Adafruit_HTU21DF();
}

void htu21d_interface::setup_htu()
{
  if (!htu.begin() || !Serial)
  {
    Serial.println(F("Couldn't find sensor!"));
    while (1)
      ;
  }
}
void htu21d_interface::debug_serial()
{
  htu_data data = read_htu();
  Serial.print(F("{sensor: 'htu21d' { temperature: "));
  Serial.print(data.temperature, 2);
  Serial.print(F(" ºC, humidity: "));
  Serial.print(data.humidity);
  Serial.println(F(" % }} "));
}

htu_data htu21d_interface::read_htu()
{
  htu_data result;
  result.temperature = htu.readTemperature();
  result.humidity = htu.readHumidity();
  return result;
}
