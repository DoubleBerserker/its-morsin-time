#include <cmath>
#include "Oscillator.h"

Oscillator::Oscillator(float freq, float amp) : frequency(freq), amplitude(amp), angle(0.0f){
    offset = 2 * M_PI * frequency / sampleRate;
}

float Oscillator::process() {
    auto sample = amplitude * sin(angle);
    angle += offset;
    return sample;
}

void Oscillator::reset() {
    angle = 0.0f;
}