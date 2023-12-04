#include "txt2morse.h"

void txt2morse(float freq) {
    std::string input;
    std::cout << "Enter plaintext to convert:";
    std::cin.ignore();
    std::getline(std::cin, input);

    std::ofstream file;
    file.open("morse.wav", std::ios::binary);

    Oscillator oscillator(freq, 0.5);

    wavMetadata(file);
    int preAudioPosition = file.tellp();

    characters Sentence(input);

    Sentence.toMorse();
    Sentence.writeMorse(file, oscillator);

    int postAudioPosition = file.tellp();
    file.seekp(preAudioPosition - 4);
    writeToFile(file, postAudioPosition - preAudioPosition, 4);
    file.seekp(4, std::ios::beg);
    writeToFile(file, postAudioPosition - 8, 4);

    file.close();
}