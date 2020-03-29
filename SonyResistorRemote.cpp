/*
  Sony Resistor Remote

  Provides an interface for Sony control devices that use resistor ladders to determine
  which controls have been triggered.

  Written by Adam J. Bauman.
  BSD license, all text above must be included in any redistribution
 */

#include "Arduino.h"
#include "SonyResistorRemote.h"

//bool is_in_range(int )

SonyRM_MC25C::SonyRM_MC25C(const int analog_in_pin) : m_analog_in_pin(analog_in_pin) 
//SonyRM_MC25C::SonyRM_MC25C(const int analog_in_pin)
{
    m_analog_in_pin = analog_in_pin;
    pinMode(m_analog_in_pin, INPUT);
}


SonyRM_MC25C::~SonyRM_MC25C() {}


SonyCommand SonyRM_MC25C::Read() 
{
    int analog_value = analogRead(m_analog_in_pin);

    using namespace SonyResistorRemote;
    
    SonyCommand sony_command;
    if (analog_value > RM_MC25C::PlayPause::MinValue && analog_value < RM_MC25C::PlayPause::MaxValue) { 
        sony_command.control = Control::PlayPause;
        sony_command.debounce_ms = RM_MC25C::PlayPause::DebounceMS;
        sony_command.analog_in_value = analog_value;
    }
    else if (analog_value > RM_MC25C::Stop::MinValue && analog_value < RM_MC25C::Stop::MaxValue) { 
        sony_command.control = Control::Stop;
        sony_command.debounce_ms = RM_MC25C::Stop::DebounceMS;
        sony_command.analog_in_value = analog_value;
    }
    else if (analog_value > RM_MC25C::TwistRight::MinValue && analog_value < RM_MC25C::TwistRight::MaxValue) { 
        sony_command.control = Control::TwistRight;
        sony_command.debounce_ms = RM_MC25C::TwistRight::DebounceMS;
        sony_command.analog_in_value = analog_value;
    }
    else if (analog_value > RM_MC25C::TwistLeft::MinValue && analog_value < RM_MC25C::TwistLeft::MaxValue) {
        sony_command.control = Control::TwistLeft;
        sony_command.debounce_ms = RM_MC25C::TwistLeft::DebounceMS;
        sony_command.analog_in_value = analog_value;
    }
    else if (analog_value > RM_MC25C::TwistRightShift::MinValue && analog_value < RM_MC25C::TwistRightShift::MaxValue) {
        sony_command.control = Control::TwistRightShift;
        sony_command.debounce_ms = RM_MC25C::TwistRightShift::DebounceMS;
        sony_command.analog_in_value = analog_value;
    }
    else if (analog_value > RM_MC25C::TwistLeftShift::MinValue && analog_value < RM_MC25C::TwistLeftShift::MaxValue) { 
        sony_command.control = Control::TwistLeftShift;
        sony_command.debounce_ms = RM_MC25C::TwistLeftShift::DebounceMS;
        sony_command.analog_in_value = analog_value;
    }
    else {
      sony_command.control = Control::Unknown;
    }

    return(sony_command);
}
