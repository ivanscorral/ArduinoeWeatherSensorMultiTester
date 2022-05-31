#ifndef HDC1080_INTERFACE_H
#define HDC1080_INTERFACE_H
#include "sensor_structs.h"
#include "ClosedCube_HDC1080.h"
#include "Wire.h"

#define hdc1080_addr 0x40



class hdc1080_interface
{
private:
    ClosedCube_HDC1080 hdc; // I2C
    void printSerialnumber();
public:
    void debug_sensor();
    void setup_sensor();
    sensor_data read_sensor();
    hdc1080_interface();
    ~hdc1080_interface();
};
#endif
