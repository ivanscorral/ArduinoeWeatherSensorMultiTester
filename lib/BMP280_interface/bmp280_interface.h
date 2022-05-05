#ifndef BMP_INTERFACE_H
#define BMP_INTERFACE_H
#include <Adafruit_BMP280.h>

#define BMP_SCK (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS (10)

#define BMP_ADDR 0x76

typedef struct sensor_data
{
    float temperature;
    float pressure_hPa;
    float altitude;
} sensor_data;

class bmp280_interface
{
private:
    Adafruit_BMP280 bmp; // I2C
    uint16_t i2c_addr;

public:
    uint16_t get_i2c_addr();
    void debug_serial(float sea_level_pressure = 1013.25f);
    void setup_bmp(uint16_t i2c_addr);
    sensor_data read_bmp(float sea_level_pressure = 1013.25f);
    bmp280_interface();
    ~bmp280_interface();
};
#endif
