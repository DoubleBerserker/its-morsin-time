#ifndef MORSIN_TIME_METADATA_H
#define MORSIN_TIME_METADATA_H

#include <fstream>
#include "consts.h"

void writeToFile(std::ofstream &file, int value, int size);
void wavMetadata(std::ofstream &file);

#endif //MORSIN_TIME_METADATA_H
