#include <iostream>
#include <fstream>
#include "includes/Oscillator.h"
#include "includes/ditDash.h"
#include "includes/metadata.h"

int main(){
    std::ofstream audioFile;
    audioFile.open("waveform.wav", std::ios::binary);

    Oscillator oscillator(440, 0.5);

    wavMetadata(audioFile);

    int preAudioPosition = audioFile.tellp();   // Position of stream pointer before audio data

    // S - dit dit dit
    dit(audioFile, oscillator);
    dit(audioFile, oscillator);
    dit(audioFile, oscillator);

    charSpace(audioFile);

    // O - dash dash dash
    dash(audioFile, oscillator);
    dash(audioFile, oscillator);
    dash(audioFile, oscillator);

    charSpace(audioFile);

    // S - dit dit dit
    dit(audioFile, oscillator);
    dit(audioFile, oscillator);
    dit(audioFile, oscillator);

    int postAudioPosition = audioFile.tellp();  // Position of stream pointer after audio data
    audioFile.seekp(preAudioPosition - 4);  // Seek to the size of file sub-chunk in metadata
    // v Write the size of DATA sub-chunk in the metadata v
    writeToFile(audioFile, postAudioPosition - preAudioPosition, 4);
    audioFile.seekp(4, std::ios::beg);  // Seek to the chunk-size offset in metadata
    // v Size of (entire file - RIFF & size of chunk) v
    writeToFile(audioFile, postAudioPosition - 8, 4);

    audioFile.close();
    return 0;
}