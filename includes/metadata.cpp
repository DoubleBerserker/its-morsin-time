#include "metadata.h"

void writeToFile(std::ofstream &file, int value, int size) {
    file.write(reinterpret_cast<const char *>(&value), size);
}

void wavMetadata(std::ofstream &file) {
    // HEADER chunk
    file << "RIFF";
    file << "----"; // Placeholder: Size of the complete chunk (HEADER + FORMAT + DATA)
    file << "WAVE";

    // FORMAT chunk
    file << "fmt ";
    writeToFile(file, 16, 4);   // Chunk data size
    writeToFile(file, 1, 2);    // Compression Code: 1 - PCM/uncompressed
    writeToFile(file, 1, 2);    // Number of channels: 1 - Mono
    writeToFile(file, sampleRate, 4);   // SampleRate: 44.1k
    // Bytes per second: [sampleRate * bitDepth * no. of channels(1)]/ 8 (bit to byte)
    writeToFile(file, (sampleRate * bitDepth / 8), 4);  // Bytes per second
    writeToFile(file, bitDepth / 8, 2); // Block align
    writeToFile(file, bitDepth, 2); // bitDepth

    // DATA chunk
    file << "data";
    file << "----"; // Placeholder (size of file unknown at this point)
}