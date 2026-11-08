#ifndef PROGRAM_LOADER_H
#define PROGRAM_LOADER_H
#include <string>
#include <iostream>
#include <fstream>
#include "Memory.h"

using namespace std;

class ProgramLoader {
public:
    static bool loadFromFile(const string& filename, Memory& memory, int startAddress = 0);
};

#endif