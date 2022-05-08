#ifndef SHT31_INTERFACE_HEADER
#define SHT31_INTERFACE_HEADER

#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_SHT31.h"
#include "htu21d_interface.h"
#include "sensor_structs.h"

#define SHT_ADDR 0x44

class sht31_interface
{
private:
    bool enableHeater = false;
    uint8_t loopCnt = 0;
    Adafruit_SHT31 sht31;
public:
    sht31_interface();
    void switch_heater();
    void debug_sensor();
    void setup_sensor();
    sensor_data read_sensor();
};


#endif // !SHT31_INTERFACE_HEADER
