#ifndef UTILS
#define UTILS

#include <Arduino.h>
#define DIODE_ADC_SIGNAL A7
#define GENERATOR_SIGNAL_INPUT A6
#define READ_CYCLE_AMOUNT 15
#define MAXIMUM_GENERATOR_VOLTAGE_VALUE 845
#define CONTROLLER_INPUT_OPERATING_VOLTAGE 5
#define MAX_ADC_VALUE 1023
#define ADC_GENERATOR_DELTA_STEP 3

namespace Utils{
    double fromADCToVoltage(int&);
}

#endif