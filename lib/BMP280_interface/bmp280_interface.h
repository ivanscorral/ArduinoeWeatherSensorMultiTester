#ifndef BMP_INTERFACE_H
#define BMP_INTERFACE_H
#include "sensor_structs.h"
#include <Adafruit_BMP280.h>

#define BMP_SCK (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS (10)

#define BMP_ADDR 0x76



class bmp280_interface
{
private:
    Adafruit_BMP280 bmp; // I2C
    uint16_t i2c_addr;
    float sea_level_p;
public:
    uint16_t get_i2c_addr();
    void debug_sensor();
    void setup_sensor(uint16_t i2c_addr);
    sensor_data read_sensor();
    bmp280_interface(float sea_level_pressure);
    ~bmp280_interface();
};
#endif
