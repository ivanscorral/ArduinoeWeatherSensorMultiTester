
#ifndef HDC1080_INTERFACE_H
#define HDC1080_INTERFACE_H
#include "sensor_structs.h"
#include "Adafruit_AHX.h"
#include "Wire.h"


class aht_interface
{
private:
    Adafruit_AHTX0 aht;
public:
    void debug_sensor();
    void setup_sensor();
    sensor_data read_sensor();
    aht_interface();
    ~aht_interface();
};
#endif
