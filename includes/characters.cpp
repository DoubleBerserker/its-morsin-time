#include "characters.h"

#include <utility>

characters::characters(std::string input) {
    inputText = std::move(input);
    std::transform(inputText.begin(), inputText.end(), inputText.begin(), tolower);
    charMap = {
            {'a', "01"},
            {'b', "1000"},
            {'c', "1010"},
            {'d', "100"},
            {'e', "0"},
            {'f', "0010"},
            {'g', "110"},
            {'h', "0000"},
            {'i', "00"},
            {'j', "0111"},
            {'k', "101"},
            {'l', "0100"},
            {'m', "11"},
            {'n', "10"},
            {'o', "111"},
            {'p', "0110"},
            {'q', "1101"},
            {'r', "010"},
            {'s', "000"},
            {'t', "1"},
            {'u', "001"},
            {'v', "0001"},
            {'w', "011"},
            {'x', "1001"},
            {'y', "1011"},
            {'z', "1100"},
            {' ', "."}
    };
}

void characters::dit(std::ofstream &file, Oscillator oscillator) {
    oscillator.reset();
    for (int i = 0; i < static_cast<int>(sampleRate * unitDuration); i++) {
        auto sample = oscillator.process();
        int intSample = static_cast<int>(sample * maxAmplitude);
        file.write(reinterpret_cast<char *>(&intSample), 2);
    }
}

void characters::dash(std::ofstream &file, Oscillator oscillator) {
    oscillator.reset();
    for (int i = 0; i < static_cast<int>(sampleRate * unitDuration * 3); i++) {
        auto sample = oscillator.process();
        int intSample = static_cast<int>(sample * maxAmplitude);
        file.write(reinterpret_cast<char *>(&intSample), 2);
    }
}

void characters::empty(std::ofstream &file) {
    for(int i = 0; i < static_cast<int> (sampleRate * unitDuration); i++){
        int intSample = 0;
        file.write(reinterpret_cast<char *>(&intSample), 2);
    }
}

void characters::toMorse() {
    for(char & it : inputText) {
        if(isalnum(it))
            morseText.append(charMap[it]).append("...");
    }
    std::cout << morseText;
}

void characters::writeMorse(std::ofstream &file, Oscillator oscillator) {
    for(char & it : morseText) {
        if (it == '0') {
            empty(file);
            dit(file, oscillator);
        }
        else if (it == '1') {
            empty(file);
            dash(file, oscillator);
        }
        else if (it == '.')
            empty(file);
    }
}
