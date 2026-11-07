#include "Volemachine.h"
#include <iostream>

using namespace std;

VoleMachine::VoleMachine() : memory(256), registers(16), programCounter(0) {}

Memory& VoleMachine::getMemory() {
    return memory;
}

RegisterFile& VoleMachine::getRegisterFile() {
    return registers;
}

int VoleMachine::getProgramCounter() const {
    return programCounter;
}

void VoleMachine::setProgramCounter(int pc) {
    programCounter = pc;
}

void VoleMachine::reset() {
    memory = Memory(256);
    registers = RegisterFile(16);
    programCounter = 0;
}