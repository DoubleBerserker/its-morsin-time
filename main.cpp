#include <iostream>
#include <fstream>
#include "includes/Oscillator.h"
#include "includes/ditDash.h"


int main(){
    std::ofstream audioFile;
    audioFile.open("waveform", std::ios::binary);
    Oscillator oscillator(440, 0.5);

    // S - dit dit dit
    dit(audioFile, oscillator);
    dit(audioFile, oscillator);
    dit(audioFile, oscillator);

    charSpace(audioFile, oscillator);

    // O - dash dash dash
    dash(audioFile, oscillator);
    dash(audioFile, oscillator);
    dash(audioFile, oscillator);

    charSpace(audioFile, oscillator);

    // S - dit dit dit
    dit(audioFile, oscillator);
    dit(audioFile, oscillator);
    dit(audioFile, oscillator);

    audioFile.close();
    return 0;
}