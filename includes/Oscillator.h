#ifndef MORSIN_TIME_OSCILLATOR_H
#define MORSIN_TIME_OSCILLATOR_H

const int sampleRate = 44100;

class Oscillator {
    float frequency, amplitude, angle, offset;
public:
    Oscillator(float freq, float amp);
    float process();
    void reset();
};

#endif //MORSIN_TIME_OSCILLATOR_H
