#ifndef FILTERS
#define FILTERS

#include "Utils.hpp"

namespace Filters{
    int signalMovingAverageFilter(int (&)[READ_CYCLE_AMOUNT] , int&, int&, int&);
}

#endif