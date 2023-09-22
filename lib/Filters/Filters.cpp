#include "Filters.hpp"
#include "Utils.hpp"
#include <Arduino.h>

int Filters::signalMovingAverageFilter(int (&valueArray)[READ_CYCLE_AMOUNT], int& counter, int& sum, int& value){
    sum = sum - valueArray[counter];
    valueArray[counter] = value;
    sum += value;
    counter = (counter + 1) % READ_CYCLE_AMOUNT;
    return sum/READ_CYCLE_AMOUNT;
}