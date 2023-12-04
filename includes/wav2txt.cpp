#include "wav2txt.h"

void decoder(){
    int count = 0;
    int pos = 44;
    bool soundOrSpace = true;
    int fileSize;
    std::string morseText;

    char * buffer = new char[4];
    memset(buffer, 0, sizeof(&buffer));
    std::ifstream file("waveform.wav", std::ios::binary);

    file.seekg(0, std::ifstream::end);
    fileSize = static_cast<int>(file.tellg());
    std::cout << "File Size: " << fileSize << std::endl;

    // Load the initial buffer
    file.seekg(pos);
    file.read(&buffer[0], 4);

    while(pos < fileSize){
        if (soundOrSpace) {
            checkDitDash(file, buffer, &pos, &count);
            soundOrSpace = false;
            count == 8820 ? morseText.append("0") : morseText.append("1");
        } else {
            checkEmpty(file, buffer, &pos, &count, fileSize);
            soundOrSpace = true;
            if(count == 26460) morseText.append(" ");
        }
        std::cout << "Position after loop: " << pos << '\n';
        std::cout << "Size of section: " << count - 1 << '\n' << std::endl;
        count = 0;
    }

    std::cout << "Finished execution." << std::endl;
    std::cout << "Morse code translation: " << morseText << std::endl;
    file.close();
}


bool isZero(const char * buffer) {
    if (buffer[0] == 0x0 && buffer[1] == 0x0 && buffer[2] == 0x0 && buffer[3] == 0x0)
        return true;
    return false;
}


void checkDitDash(std::ifstream &file, char * buffer, int * pos, int * count) {
    while(!isZero(buffer)) {
        *count += 4;
        *pos += 4;
        file.seekg(*pos);
        file.read(&buffer[0], 4);
    }
}


void checkEmpty(std::ifstream &file, char * buffer, int * pos, int * count, int fileSize) {
    while(isZero(buffer) && *pos < fileSize) {
        *count += 4;
        *pos += 4;
        file.seekg(*pos);
        file.read(&buffer[0], 4);
    }
}