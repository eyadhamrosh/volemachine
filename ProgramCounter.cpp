#include<iostream>
using namespace std;
#include "ProgramCounter.h"
 
ProgramCounter::ProgramCounter() : address(0) {}
 
int ProgramCounter::getAddress() const {
    return address;
}
 
void ProgramCounter::setAddress(int addr) {
    address = addr;
}
 
void ProgramCounter::advance() {
    address += 2;
}