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

## Adding a third sensor

With proper wiring, I connnected the SHT31 sensor and was greeted with the following output on I2C scan:
```
=================================================================================================================================== [SUCCESS] Took 6.42 seconds ===================================================================================================================================
--- Available filters and text transformations: colorize, debug, default, direct, hexlify, log2file, nocontrol, printable, send_on_enter, time
--- More details at https://bit.ly/pio-monitor-filters
--- Miniterm on COM20  9600,8,N,1 ---
--- Quit: Ctrl+C | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H ---
I2C scan running for 3 times, delay is 2.50 seconds.
I2C device found at address 0x40  !
I2C device found at address 0x44  !
I2C device found at address 0x76  !
done

I2C scan running for 2 times, delay is 2.50 seconds.
I2C device found at address 0x40  !
I2C device found at address 0x44  !
I2C device found at address 0x76  !
done

I2C scan running for 1 times, delay is 2.50 seconds.
I2C device found at address 0x40  !
I2C device found at address 0x44  !
I2C device found at address 0x76  !
done

BMP280 Forced Mode Test.
FBMP280 DATA = {temperature: 27.02 ºC, pressure: 1013.07 hPa, altitude: 1.52 m} New record in 5 seconds
```

As can be seen, a new I2C device popped up on our scanner, with id 0x44, this is good, because we dont have overlapping id's (yet...).



## Reading from 2 sensors at the same (almost) time

```
HTU21D Test.
Temp: 23.67 C           Humidity: 59.96 %
BMP280 DATA = {temperature: 24.82 ºC, pressure: 1018.13 hPa, altitude: -40.54 m} 
New record in 5 seconds
HTU21D Test.
Temp: 23.62 C           Humidity: 60.09 %
BMP280 DATA = {temperature: 24.78 ºC, pressure: 1018.13 hPa, altitude: -40.56 m} 
New record in 5 seconds
HTU21D Test.
Temp: 23.57 C           Humidity: 60.20 %
BMP280 DATA = {temperature: 24.74 ºC, pressure: 1018.13 hPa, altitude: -40.56 m} 
New record in 5 seconds
HTU21D Test.
Temp: 23.54 C           Humidity: 60.33 %
BMP280 DATA = {temperature: 24.71 ºC, pressure: 1018.13 hPa, altitude: -40.56 m} 
New record in 5 seconds
HTU21D Test.
Temp: 23.73 C           Humidity: 60.38 %
BMP280 DATA = {temperature: 24.67 ºC, pressure: 1018.13 hPa, altitude: -40.54 m} 
New record in 5 seconds
HTU21D Test.
Temp: 23.65 C           Humidity: 60.56 %
BMP280 DATA = {temperature: 24.64 ºC, pressure: 1018.13 hPa, altitude: -40.55 m} 
New record in 5 seconds
HTU21D Test.
Temp: 23.62 C           Humidity: 60.73 %
BMP280 DATA = {temperature: 24.61 ºC, pressure: 1018.13 hPa, altitude: -40.55 m} 
New record in 5 seconds



```  
### After sensors warmed up
```
New record in 5 seconds
HTU21D Test.
Temp: 23.01 C           Humidity: 60.62 %
BMP280 DATA = {temperature: 23.91 ºC, pressure: 1018.13 hPa, altitude: -40.59 m} 
New record in 5 seconds
HTU21D Test.
Temp: 23.05 C           Humidity: 60.30 %
BMP280 DATA = {temperature: 23.91 ºC, pressure: 1018.14 hPa, altitude: -40.61 m} 
New record in 5 seconds
HTU21D Test.
Temp: 23.08 C           Humidity: 59.86 %
BMP280 DATA = {temperature: 23.91 ºC, pressure: 1018.13 hPa, altitude: -40.59 m} 
New record in 5 seconds
HTU21D Test.
Temp: 23.09 C           Humidity: 59.83 %
BMP280 DATA = {temperature: 23.90 ºC, pressure: 1018.14 hPa, altitude: -40.62 m} 
New record in 5 seconds
HTU21D Test.
Temp: 23.10 C           Humidity: 60.18 %
BMP280 DATA = {temperature: 23.90 ºC, pressure: 1018.14 hPa, altitude: -40.64 m} 
New record in 5 seconds
```

## Refactored and unified output

All serial prints were removed except for the functions used for debug, which has been modified to output a json file with its basic parameters. This will help future processing of data variance and reliability of each sensor. Added also local pressure level option, default is 1013.25 hPA.

**New ouput**
```
New scan in 5.00 seconds
{sensor: 'htu21d' { temperature: 23.10 ºC, humidity: 61.27 % }} 
{sensor: 'bmp280' { temperature: 24.23 ºC, pressure: 1018.55 hPa, altitude: -3.28 m }} 
New scan in 5.00 seconds
{sensor: 'htu21d' { temperature: 23.09 ºC, humidity: 61.29 % }} 
{sensor: 'bmp280' { temperature: 24.22 ºC, pressure: 1018.54 hPa, altitude: -3.24 m }} 
New scan in 5.00 seconds
{sensor: 'htu21d' { temperature: 23.09 ºC, humidity: 61.32 % }} 
{sensor: 'bmp280' { temperature: 24.22 ºC, pressure: 1018.54 hPa, altitude: -3.21 m }} 
New scan in 5.00 seconds
{sensor: 'htu21d' { temperature: 23.11 ºC, humidity: 61.33 % }} 
{sensor: 'bmp280' { temperature: 24.21 ºC, pressure: 1018.53 hPa, altitude: -3.18 m }} 
New scan in 5.00 seconds
{sensor: 'htu21d' { temperature: 23.08 ºC, humidity: 61.44 % }} 
{sensor: 'bmp280' { temperature: 24.20 ºC, pressure: 1018.53 hPa, altitude: -3.12 m }}
```
