#include "Utils.hpp"

double Utils::fromADCToVoltage(int& filteredADCValue){
    double res = (double) filteredADCValue * CONTROLLER_INPUT_OPERATING_VOLTAGE / MAX_ADC_VALUE;
    res = res * 4.2;
    res = round(res * 10)/10.0;
    return res;
}