# Low Level Buses

## RS232

Was Standard for serial communication

Used for communication with printer, mice.
Today mostly succeeded by USB.

Today still used for service config ports and PRS communication.

Asynchronous data transfer
ASCII coded

- Speed: dependend on interface, normally 1.5 Mbit/s
- Length: 
	- Standard: 15m
	- Low capacity: 300m

## I2C

Low speed bus for connection of peripherals to microcontrollers
Invented by Philips.

- Wiring:
	- USDA: data
	- Clock: USCL
- 5V or 3,3V
- 10kbit/s - 3.5Mbit/s
- Length a few meters

Both lines address room of 7 bit

Half duplex protocol.

- Examples: read EEPROM, access DAC, control OLED or LCD
ARDUINO, Linux, Mac, Windows

## SPI

- Speed: Faster than other 2 before, no speed specification found
- Wiring:
	- clock
	- master in / slave out
	- master out/ slave in
	- slave select
- Lenght: short distance, about 3m
	
Synchronous, Master Slave

Full Duplex.

Microcontrollers that communicate with peripherals.

## Onewire (researched by me)

Similar to I²C but with lower data rate and longer range.

- Wiring: only two wires: data and ground
- Speed:
	- 16.3 kbbit/s
	- 10x the speed in overdrive mode
- Max Length: 750m

Typically used for power signalling for small, inexpensive devices (digital thermometers, weather instruments).

A network of Onewire devices with associated master is called MicroLAN.

1-Wire devices include an 800 pF capacitor to store charge, and to power the device during periods when the data line is active.

Uses the 1-wire protocol

- Examples: Java Ring, iButton, Apple MagSafe for Powersupplies

# Sensing / Acting

## Sensing (1)

### Mounted ds18b20 (researched by me)

- measures 9bit to 12bit temperature values in celsius (-55°C to +125°C)
- Power supply range from 3.0V to 5.5V
- User-defined alarms (low and high temperature value for alarm)

![alt text](https://hackster.imgix.net/uploads/attachments/229740/FP8600RIFMRO359.LARGE.jpg?auto=compress%2Cformat&w=680&h=510&fit=max "ds18b20 connection")