#ifndef MORSIN_TIME_WAV2TXT_H
#define MORSIN_TIME_WAV2TXT_H


#include <string>
#include <fstream>
#include <cstring>
#include <iostream>


void decoder();
bool isZero(const char * buffer);
void checkDitDash(std::ifstream &file, char * buffer, int * pos, int * count);
void checkEmpty(std::ifstream &file, char * buffer, int * pos, int * count, int fileSize);


#endif //MORSIN_TIME_WAV2TXT_H
