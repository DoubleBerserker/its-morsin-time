#include <iostream>
#include "includes/txt2morse.h"
#include "includes/wav2txt.h"
#include <limits>

int main(){

    while(true) {
        std::cout << "Enter the operation you want to perform:[Input: 1 (or) 2]\n"
                     "1. Convert plaintext to Morse Code WAV file.\n"
                     "2. Convert Morse Code WAV file to plaintext\n"
                     "3. Exit" << std::endl;

        char choice;
        std::cin >> choice;

        switch (choice) {
            case '1': {
                float freq;
                std::cout << "Enter the frequency of sine oscillator (in Hz, default = 600):";
                std::cin >> freq;
                // Bad input handling
                if (std::cin.fail()) {
                    printf("Not a valid input!");
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                try {
                    txt2morse(freq);
                }
                catch (...) {
                    txt2morse(600.0);
                }
                std::cout << "File created!" << std::endl;
                break;
            }
            case '2': {
                decoder();
                break;
            }
            case '3': {
                std::cout << "Exiting the program." << std::endl;
                exit(0);
            }

            default: {
                std::cout << "Invalid input!" << std::endl;
                break;
            }
        }
        std::cout << "\n\n" << std::endl;
    }
}