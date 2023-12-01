#include <iostream>
#include <cmath>
#include <fstream>

const int sampleRate = 44100;
const int bitDepth = 16;
const float unitDuration = 0.1;
const auto maxAmplitude = pow(2, bitDepth - 1) - 1;

class Oscillator{
    float frequency, amplitude, angle = 0.0f, offset;
public:
    Oscillator(float freq, float amp) : frequency(freq), amplitude(amp) {
        offset = 2 * M_PI * frequency / sampleRate;
    }

    float process() {
        auto sample = amplitude * sin(angle);
        angle += offset;
        return sample;
    }

    void reset(){
        angle = 0.0f;
    }
};

void dit(std::ofstream &file, Oscillator oscillator);
void dash(std::ofstream &file, Oscillator oscillator);
void charSpace(std::ofstream &file, Oscillator oscillator);
void wordSpace(std::ofstream &file, Oscillator oscillator);

int main(){
    std::ofstream audioFile;
    audioFile.open("waveform", std::ios::binary);
    Oscillator oscillator(440, 0.5);

    // S - dit dit dit
    dit(audioFile, oscillator);
    dit(audioFile, oscillator);
    dit(audioFile, oscillator);

    charSpace(audioFile, oscillator);

    dash(audioFile, oscillator);
    dash(audioFile, oscillator);
    dash(audioFile, oscillator);

    charSpace(audioFile, oscillator);

    dit(audioFile, oscillator);
    dit(audioFile, oscillator);
    dit(audioFile, oscillator);

    audioFile.close();
    return 0;
}

void dit(std::ofstream &file, Oscillator oscillator){
    oscillator.reset();
    for(int i = 0; i < sampleRate * unitDuration; i++){
        auto sample = oscillator.process();
        int intSample = static_cast<int>(sample * maxAmplitude);
        file.write(reinterpret_cast<char *>(&intSample), 2);
    }

    for(int i = 0; i < sampleRate * unitDuration; i++){
        int intSample = 0;
        file.write(reinterpret_cast<char *>(&intSample), 2);
    }

}

void dash(std::ofstream &file, Oscillator oscillator){
    oscillator.reset();
    for(int i = 0; i < sampleRate * unitDuration * 3; i++){
        auto sample = oscillator.process();
        int intSample = static_cast<int>(sample * maxAmplitude);
        file.write(reinterpret_cast<char *>(&intSample), 2);
    }

    for(int i = 0; i < sampleRate * unitDuration; i++){
        int intSample = 0;
        file.write(reinterpret_cast<char *>(&intSample), 2);
    }

}

void charSpace(std::ofstream &file, Oscillator oscillator){
    for(int i = 0; i < sampleRate * unitDuration * 3; i++){
        int intSample = 0;
        file.write(reinterpret_cast<char *>(&intSample), 2);
    }
}

void wordSpace(std::ofstream &file, Oscillator oscillator){
    for(int i = 0; i < sampleRate * unitDuration * 3; i++){
        int intSample = 0;
        file.write(reinterpret_cast<char *>(&intSample), 2);
    }
}