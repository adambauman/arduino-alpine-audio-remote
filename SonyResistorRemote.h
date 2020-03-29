/*
  Sony Resistor Remote

  Provides an interface for Sony control devices that use resistor ladders to determine
  which controls have been triggered.

  Written by Adam J. Bauman.
  BSD license, all text above must be included in any redistribution
 */

#pragma once

//NOTE: (Adam) 2020-02-23 These values were set using a 5v ATmega32U4 board with power supplied by the VCC pin with a
//      10k pull-down resistor to ground. The board this was original designed for lacked an AREF pin and was averaging
//      about 5% of variance. Use these values as a baseline and tune for your particular hardware, you may also want
//      to tweak debounce depending on how loosy-goosy your Sony controller is.
namespace SonyResistorRemote {

    enum Control {
        Unknown,
        PlayPause,
        Stop,
        TwistRight,
        TwistLeft,
        TwistRightShift, // Usually pushing down the control ring then twisting
        TwistLeftShift,
    };

    namespace RM_MC25C{
        namespace PlayPause {
            constexpr int MinValue = 955;
            constexpr int MaxValue = 1000;
            constexpr int DebounceMS = 300;
        }
        namespace Stop {
            constexpr int MinValue = 550;
            constexpr int MaxValue = 625;
            constexpr int DebounceMS = 300;
        }
        namespace TwistRight {
            constexpr int MinValue = 700;
            constexpr int MaxValue = 800;
            constexpr int DebounceMS = 100;
        }
        namespace TwistLeft {
            constexpr int MinValue = 825;
            constexpr int MaxValue = 945; // Approaching lower limit of PlayPause
            constexpr int DebounceMS = 100;
        }
        namespace TwistRightShift {
            constexpr int MinValue = 400;
            constexpr int MaxValue = 500;
            constexpr int DebounceMS = 300;
        }
        namespace TwistLeftShift {
            constexpr int MinValue = 635; // Approaching upper limit of Stop
            constexpr int MaxValue = 690; // Approaching lower limit of SpinRight
            constexpr int DebounceMS = 300;
        }
    }
}


struct SonyCommand {
    SonyResistorRemote::Control control = SonyResistorRemote::Control::Unknown;
    int debounce_ms = 0;
    int analog_in_value = 0;
};

class SonyRM_MC25C {
public:
    SonyRM_MC25C(const int analog_in_pin);
    ~SonyRM_MC25C();

    SonyCommand Read();

private:
    int m_analog_in_pin = 0;
};
