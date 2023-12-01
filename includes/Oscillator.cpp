#include "Oscillator.h"

Oscillator::Oscillator(float freq, float amp) : frequency(freq), amplitude(amp), angle(0.0f){
    offset = static_cast<float>(2 * M_PI * frequency / sampleRate);
}

float Oscillator::process() {
    auto sample = amplitude * sin(angle);
    angle += offset;
    return static_cast<float>(sample);
}

inline void Oscillator::reset() {
    angle = 0.0f;
}