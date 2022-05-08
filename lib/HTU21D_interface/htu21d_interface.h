#ifndef HTU21D_INTERFACE_HEADER
#define HTU21D_INTERFACE_HEADER

#include <Wire.h>
#include "Adafruit_HTU21DF.h"
#include "sensor_structs.h"

class htu21d_interface
{
private:
    Adafruit_HTU21DF htu;

public:
    void setup_sensor();
    void debug_sensor();
    sensor_data read_sensor();
    htu21d_interface();
};
#endif
