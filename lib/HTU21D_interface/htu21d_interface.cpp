#include "htu21d_interface.h"

htu21d_interface::htu21d_interface()
{
    htu = Adafruit_HTU21DF();
}


void htu21d_interface::setup_htu() {
  if (!htu.begin() || !Serial) {
    Serial.println("Couldn't find sensor!");
    while (1);
  }
}

htu_data htu21d_interface::read_htu(uint8_t iterations, uint16_t totalTime_s){
    Serial.println(F("HTU21D Test."));
    htu_data result;
    result.temperature = htu.readTemperature();
    result.humidity = htu.readHumidity();
    Serial.print("Temp: "); Serial.print(result.temperature); Serial.print(" C");
    Serial.print("\t\t");
    Serial.print("Humidity: "); Serial.print(result.humidity); Serial.println(" \%");
    return result;
}

