#ifndef MORSIN_TIME_CHARACTERS_H
#define MORSIN_TIME_CHARACTERS_H

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include "Oscillator.h"
#include "consts.h"

typedef std::map<char, std::string> characterMap;

class characters {
    std::string inputText;
    std::string morseText;
    characterMap charMap;
public:
    explicit characters(std::string input);
    void toMorse();
    void writeMorse(std::ofstream &file, Oscillator oscillator);

    static void dit(std::ofstream &file, Oscillator oscillator);
    static void dash(std::ofstream &file, Oscillator oscillator);
    static void empty(std::ofstream &file);
};


#endif //MORSIN_TIME_CHARACTERS_H
