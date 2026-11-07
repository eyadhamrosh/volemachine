#include <iostream>
#ifndef MEMORY_H
#define MEMORY_H
#include <string>
#include <vector>

using namespace std;

class Memory {
private:
    vector<string> cells;

public:
    Memory(int size = 256);
    string getCell(int address) const;
    void setCell(int address, const string& value);
    int getSize() const;
    void display() const;
};

#endif