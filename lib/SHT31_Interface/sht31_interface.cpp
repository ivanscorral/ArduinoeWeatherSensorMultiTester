#include "sht31_interface.h"

sht31_interface::sht31_interface()
{
    sht31 = Adafruit_SHT31();
}

void sht31_interface::setup_sensor()
{
    while (!Serial)
        delay(10);

#ifdef DEBUG
    Serial.println("SHT31 test");
#endif
    if (!sht31.begin(SHT_ADDR))
    {
#ifdef DEBUG
        Serial.println("Couldn't find SHT31");
#endif // DEBUG
        while (1)
            delay(1);
    }
}

sensor_data sht31_interface::read_sensor()
{
    sensor_data result;
    result.temperature = sht31.readTemperature();
    result.humidity = sht31.readHumidity();
    delay(10);
    switch_heater();
    return result;
}

void sht31_interface::debug_sensor()
{
    sensor_data data = read_sensor();
    if (!isnan(data.temperature) && !isnan(data.humidity))
    {
        Serial.print(F("\n{sensor: 'sht31' { temperature = '"));
        Serial.print(data.temperature);
        Serial.print(F(" ºC', humidity: '"));
        Serial.print(data.humidity);
        Serial.println(F(" %'}}"));
    }
}

void sht31_interface::switch_heater()
{
    delay(1000);

    if (loopCnt >= 30)
    {
        enableHeater = !enableHeater;
        sht31.heater(enableHeater);
#ifdef DEBUG
        Serial.print(F("Heater Enabled State: "));
        if (sht31.isHeaterEnabled())
            Serial.println("ENABLED");
        else
            Serial.println("DISABLED");
#endif // DEBUG

        loopCnt = 0;
    }
    loopCnt++;
}