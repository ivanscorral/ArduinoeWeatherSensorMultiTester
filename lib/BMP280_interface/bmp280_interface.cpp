#include "bmp280_interface.h"

bmp280_interface::bmp280_interface(){
    i2c_addr = 0x0;
}
bmp280_interface::~bmp280_interface(){}


void bmp280_interface::setup_bmp(uint16_t i2c_address) {
    i2c_addr = i2c_address;
      if (!bmp.begin(i2c_addr)) {
        Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
                      "try a different address!"));
         while (1) delay(10);
  }

  bmp.setSampling(Adafruit_BMP280::MODE_FORCED,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

void bmp280_interface::debug_serial(){
      sensor_data data = read_bmp();
        Serial.print("BMP280 DATA = {temperature: ");
        Serial.print(data.temperature, 2);
        Serial.print (" ºC, pressure: ");
        Serial.print(data. pressure_hPa);
        Serial.print (" hPa, altitude: ");
        Serial.print(data.altitude);
        Serial.print(" m} ");
}
sensor_data bmp280_interface::read_bmp(){
    sensor_data result; 
    if (bmp280_interface::bmp.takeForcedMeasurement()) {
        // can now print out the new measurements
        result.temperature = bmp.readTemperature();
        result.pressure_hPa = bmp.readPressure() / 100.0f;

        result.altitude = bmp.readAltitude(1013.25); /* Adjusted to local forecast! */

        delay(2000);
  } else {
        Serial.println("Forced measurement failed!");
  }
        return result;

}