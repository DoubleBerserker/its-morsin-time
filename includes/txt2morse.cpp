#include "txt2morse.h"

void text2morse(int freq) {
    std::ofstream file("morse.wav", std::ios::binary);

    Oscillator oscillator(freq, 0.5);

    wavMetadata(file);
    int preAudioPosition = file.tellp();

    std::string input;
    std::cout << "Enter plaintext to convert into Morse code: ";
    std::getline(std::cin, input);
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