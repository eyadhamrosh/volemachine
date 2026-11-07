#include "ProgramLoader.h"
#include <fstream>
#include <iostream>

using namespace std;

bool ProgramLoader::loadFromFile(const string& filename, Memory& memory, int startAddress) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << "\n";
        return false;
    }

    string instruction;
    int currentAddress = startAddress;
    while (file >> instruction) {
        memory.setCell(currentAddress++, instruction);
    }

    file.close();
    return true;
}