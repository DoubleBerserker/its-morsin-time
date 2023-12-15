# Morsin Time
A C++ package to convert plaintext into a WAV file containing the generated morse code.It can also convert WAV file generated back to plaintext.

Currently under development.

## To create an executable of the program:

- Need to have a C++ compiler installed (preferably MinGW)
- Run the following shell command in the root directory of the project

`g++ -o main.exe main.cpp includes\characters.cpp includes\metadata.cpp includes\Oscillator.cpp includes\txt2morse.cpp includes\wav2txt.cpp`
