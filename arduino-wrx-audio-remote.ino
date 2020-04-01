/*
  WRX Audio Remote

  Provides a physical control interface for a touchscreen Alpine head unit, for this
  vehicle the interface of choice is a Sony RM-MC25C rotary commander.

  Communication with the head unit is provided by Mattias Winther's AlpineRemote library.

  Written by Adam J. Bauman.
  BSD license, all text above must be included in any redistribution
 */

#include "AlpineRemote.h"
#include "SonyResistorRemote.h"

// Uncomment to enable debug output to serial console.
#define _DEBUG;

constexpr int alpine_remote_pin = 3; // Plug tip, sleeve and/or ring connected to Arduino GND bus.
constexpr int sony_resistor_remote_pin = A0; // Input from Sony resistor remote, use with 10K pulldown resistor

// Initialize the Alpine remote output and Sony remote input bits.
AlpineRemote alpine_output(alpine_remote_pin);
SonyRM_MC25C sony_input(sony_resistor_remote_pin);

void setup() 
{
#ifdef _DEBUG
    Serial.begin(9600);
#endif
}

void loop() 
{
  //TODO: Send commands, debounce on sony_command.debounce_ms
  // Read the Sony remote and act on any incoming commands.
  SonyCommand sony_command = sony_input.Read();
  switch(sony_command.control) {
    case SonyResistorRemote::Control::PlayPause:
        Serial.println("PlayPause");
        break;

    case SonyResistorRemote::Control::Stop:
        Serial.println("Stop");
        break;

    case SonyResistorRemote::Control::TwistRight:
        Serial.println("Spin Right");
        break;

    case SonyResistorRemote::Control::TwistLeft:
        Serial.println("Spin Left");
        break;

    case SonyResistorRemote::Control::TwistRightShift:
        Serial.println("Spin Right Shifted");
        break;

    case SonyResistorRemote::Control::TwistLeftShift:
        Serial.println("Spin Left Shifted");
        break;
    
    default:
        break;
  }

#ifdef _DEBUG
  // Display some debug info if we have a possible command
  if(10 < sony_command.analog_in_value) {
    Serial.println(sony_input.GetControlName(sony_command.control));
    Serial.print("Analog value: ");
    Serial.println(sony_command.analog_in_value);
  }
#endif


  delay(sony_command.debounce_ms);

}
