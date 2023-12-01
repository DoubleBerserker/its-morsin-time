#ifndef MORSIN_TIME_DITDASH_H
#define MORSIN_TIME_DITDASH_H

#include <fstream>
#include "Oscillator.h"
#include "consts.h"

void dit(std::ofstream &file, Oscillator oscillator);
void dash(std::ofstream &file, Oscillator oscillator);
void charSpace(std::ofstream &file, Oscillator oscillator);
void wordSpace(std::ofstream &file, Oscillator oscillator);

#endif //MORSIN_TIME_DITDASH_H