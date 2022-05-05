#ifndef HTU21D_INTERFACE_HEADER
#define HTU21D_INTERFACE_HEADER

#include <Wire.h>

#include "Adafruit_HTU21DF.h"

typedef struct htu_data {
    float temperature;
    float humidity;
} htu_data;

class htu21d_interface
{
private:
    Adafruit_HTU21DF htu;
public:
    void setup_htu();
    htu_data read_htu(uint8_t iterations, uint16_t totalTime_s);
    htu21d_interface();
};
#endif
