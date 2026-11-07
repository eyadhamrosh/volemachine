#include "Memory.h"
#include <iostream>

using namespace std;

Memory::Memory(int size) {
    cells.resize(size, "00");
}

string Memory::getCell(int address) const {
    if (address >= 0 && address < cells.size()) {
        return cells[address];
    }
    return "00";
}

void Memory::setCell(int address, const string& value) {
    if (address >= 0 && address < cells.size()) {
        cells[address] = value;
    }
}

int Memory::getSize() const {
    return cells.size();
}

void Memory::display() const {
    cout << " Memory Dump \n";
    for (size_t i = 0; i < cells.size(); ++i) {
        if (cells[i] != "00") {
            cout << "[" << i << "]: " << cells[i] << "\n";
        }
    }
}