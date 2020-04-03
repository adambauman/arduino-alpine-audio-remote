### Introduction
Provides a physical control interface for a touchscreen Alpine head unit, for this vehicle the interface of choice is a Sony RM-MC25C rotary commander.

Communication to the Alpine head unit is provided by Mattias Winther's AlpineRemote library: https://github.com/Wnthr/arduino-alpine-remote

### Hardware
This is the hardware I used for my install.

1x Sony RM-MC25C rotary commander, uses a resistor ladder to send commands to older Sony devices like Minidisc and CD players. I removed the original Sony connector and wired one end of the data line to the Pro Micro's A0, the other to VCC.

1x Sparkfun Pro Micro clone, the 5V 16Mhz version. 

1x Automotive 12v->5V USB adapter, gutted with 5V output connected directly to the Pro Micro's RAW pin.


