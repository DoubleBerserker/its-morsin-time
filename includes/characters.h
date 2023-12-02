#ifndef MORSIN_TIME_CHARACTERS_H
#define MORSIN_TIME_CHARACTERS_H

#include <iostream>
#include <string>
#include <map>

typedef std::map<char, std::string> characterMap;

class characters {
    characterMap charMap = {
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
            {'z', "1100"}
    };

public:
    void printMorse();
};


#endif //MORSIN_TIME_CHARACTERS_H
