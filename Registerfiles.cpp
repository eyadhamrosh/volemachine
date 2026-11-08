#include "Registerfiles.h"
#include <iostream>

using namespace std;

RegisterFile::RegisterFile(int size) {
    registers.resize(size, "00");
}

string RegisterFile::getRegister(int index) const {
    if (index >= 0 && index < registers.size()) {
        return registers[index];
    }
    return "00";
}

void RegisterFile::setRegister(int index, const string& value) {
    if (index >= 0 && index < registers.size()) {
        registers[index] = value;
    }
}

void RegisterFile::display() const {
    cout << " Register File \n";
    for (size_t i = 0; i < registers.size(); ++i) {
        cout << "R" << i << ": " << registers[i] << "\n";
    }
}