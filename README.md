# ArduinoeWeatherSensorMultiTester
Project for measuring various temperature sensors connected in parallel via I2C

## Example output as of 04052022 @ commmit 463600788019ee250e376094c15926ca65ade84d

--Example before i2c scan was added--
```
=================================================================================================================================== [SUCCESS] Took 7.87 seconds ===================================================================================================================================
--- Available filters and text transformations: colorize, debug, default, direct, hexlify, log2file, nocontrol, printable, send_on_enter, time
--- More details at https://bit.ly/pio-monitor-filters
--- Miniterm on COM19  9600,8,N,1 ---
--- Quit: Ctrl+C | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H ---
BMP280 Forced Mode Test.
BMP280 DATA = {temperature: 25.13 ºC, pressure: 1012.68 hPa, altitude: 4.78 m}New record in 5 seconds
BMP280 DATA = {temperature: 25.11 ºC, pressure: 1012.68 hPa, altitude: 4.77 m}New record in 5 seconds
BMP280 DATA = {temperature: 25.09 ºC, pressure: 1012.69 hPa, altitude: 4.71 m}New record in 5 seconds
BMP280 DATA = {temperature: 25.08 ºC, pressure: 1012.69 hPa, altitude: 4.68 m}New record in 5 seconds
BMP280 DATA = {temperature: 25.07 ºC, pressure: 1012.69 hPa, altitude: 4.64 m}New record in 5 seconds
BMP280 DATA = {temperature: 25.06 ºC, pressure: 1012.69 hPa, altitude: 4.62 m}New record in 5 seconds
BMP280 DATA = {temperature: 25.05 ºC, pressure: 1012.70 hPa, altitude: 4.58 m}New record in 5 seconds
BMP280 DATA = {temperature: 25.04 ºC, pressure: 1012.70 hPa, altitude: 4.55 m}New record in 5 seconds
BMP280 DATA = {temperature: 25.03 ºC, pressure: 1012.71 hPa, altitude: 4.51 m}New record in 5 seconds
BMP280 DATA = {temperature: 25.02 ºC, pressure: 1012.71 hPa, altitude: 4.47 m}New record in 5 seconds
BMP280 DATA = {temperature: 25.01 ºC, pressure: 1012.72 hPa, altitude: 4.45 m}New record in 5 seconds
BMP280 DATA = {temperature: 25.00 ºC, pressure: 1012.72 hPa, altitude: 4.44 m}New record in 5 seconds
```

## Scanning I2C addresses

A small helper was develop which will execute x times before running the script, it will print all the I2C devices connected to the bus.

Example output with 5 iterations and code for BMP280:

```
=================================================================================================================================== [SUCCESS] Took 7.59 seconds ===================================================================================================================================
--- Available filters and text transformations: colorize, debug, default, direct, hexlify, log2file, nocontrol, printable, send_on_enter, time
--- More details at https://bit.ly/pio-monitor-filters
--- Miniterm on COM20  9600,8,N,1 ---
--- Quit: Ctrl+C | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H ---
␀␀�I2C SCAN RUNNING FOR 5 TIMES.
Scanning...
I2C device found at address 0x40  !
I2C device found at address 0x76  !
done

Scanning...
I2C device found at address 0x40  !
I2C device found at address 0x76  !
done

Scanning...
I2C device found at address 0x40  !
I2C device found at address 0x76  !
done

Scanning...
I2C device found at address 0x40  !
I2C device found at address 0x76  !
done

Scanning...
I2C device found at address 0x40  !
I2C device found at address 0x76  !
done

BMP280 Forced Mode Test.
BMP280 DATA = {temperature: 24.78 ºC, pressure: 1012.93 hPa, altitude: 2.65 m} New record in 5 seconds
BMP280 DATA = {temperature: 24.78 ºC, pressure: 1012.93 hPa, altitude: 2.64 m} New record in 5 seconds
```

## I2C scanner configurable

A few changes are made to i2c scanner, with customizable delay between reads and more loggging, example output:

```
=================================================================================================================================== [SUCCESS] Took 6.52 seconds ===================================================================================================================================
--- Available filters and text transformations: colorize, debug, default, direct, hexlify, log2file, nocontrol, printable, send_on_enter, time
--- More details at https://bit.ly/pio-monitor-filters
--- Miniterm on COM20  9600,8,N,1 ---
--- Quit: Ctrl+C | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H ---
␀␀ setup done
I2C scan running for 3 times, delay is 2.50 seconds.
I2C device found at address 0x40  !
I2C device found at address 0x76  !
done

I2C scan running for 2 times, delay is 2.50 seconds.
I2C device found at address 0x40  !
I2C device found at address 0x76  !
done

I2C scan running for 1 times, delay is 2.50 seconds.
I2C device found at address 0x40  !
I2C device found at address 0x76  !
done

BMP280 Forced Mode Test.
FBMP280 DATA = {temperature: 24.29 ºC, pressure: 1012.97 hPa, altitude: 2.34 m} New record in 5 seconds
FBMP280 DATA = {temperature: 24.29 ºC, pressure: 1012.97 hPa, altitude: 2.35 m} New record in 5 seconds
```