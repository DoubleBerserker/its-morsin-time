#include "ditDash.h"

void dit(std::ofstream &file, Oscillator oscillator) {
    oscillator.reset();
    for (int i = 0; i < static_cast<int>(sampleRate * unitDuration); i++) {
        auto sample = oscillator.process();
        int intSample = static_cast<int>(sample * maxAmplitude);
        file.write(reinterpret_cast<char *>(&intSample), 2);
    }
    for(int i = 0; i < static_cast<int> (sampleRate * unitDuration); i++){
        int intSample = 0;
        file.write(reinterpret_cast<char *>(&intSample), 2);
    }
}

void dash(std::ofstream &file, Oscillator oscillator) {
    oscillator.reset();
    for (int i = 0; i < static_cast<int>(sampleRate * unitDuration * 3); i++) {
        auto sample = oscillator.process();
        int intSample = static_cast<int>(sample * maxAmplitude);
        file.write(reinterpret_cast<char *>(&intSample), 2);
    }
    for(int i = 0; i < static_cast<int>(sampleRate * unitDuration); i++){
        int intSample = 0;
        file.write(reinterpret_cast<char *>(&intSample), 2);
    }
}

void charSpace(std::ofstream &file){
    for(int i = 0; i < static_cast<int>(sampleRate * unitDuration * 3); i++){
        int intSample = 0;
        file.write(reinterpret_cast<char *>(&intSample), 2);
    }
}

void wordSpace(std::ofstream &file){
    for(int i = 0; i < static_cast<int>(sampleRate * unitDuration * 3); i++){
        int intSample = 0;
        file.write(reinterpret_cast<char *>(&intSample), 2);
    }
}
