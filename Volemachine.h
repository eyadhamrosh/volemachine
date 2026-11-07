#ifndef VOLE_MACHINE_H
#define VOLE_MACHINE_H
#include "Memory.h"
#include "Registerfiles.h"
#include "CPU.h"
#include "Instruction.h"
#include "instruction_executor.h"
#include "Screen.h"

using namespace std;

class VoleMachine {
    private:
        Memory memory;
        RegisterFile registers;
        int programCounter;

    public:
        VoleMachine();
        Memory& getMemory();
        RegisterFile& getRegisterFile();
        int getProgramCounter() const;
        void setProgramCounter(int pc);
        void reset();
};

#endif