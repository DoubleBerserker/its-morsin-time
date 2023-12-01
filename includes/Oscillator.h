#ifndef MORSIN_TIME_OSCILLATOR_H
#define MORSIN_TIME_OSCILLATOR_H

#include <cmath>
#include "consts.h"

class Oscillator {
    float frequency, amplitude, angle, offset;
public:
    Oscillator(float freq, float amp);
    float process();
    void reset();
};

#endif //MORSIN_TIME_OSCILLATOR_H
