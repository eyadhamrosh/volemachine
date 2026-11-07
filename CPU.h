#ifndef CPU_H
#define CPU_H
#include "ProgramCounter.h"
#include "InstructionRegister.h"
#include "InstructionDecoder.h"
#include "InstructionExecutor.h"   // Person 1
#include "Instruction.h"           // Person 1
#include "ExecutionOutcome.h"      // Person 1
#include "RegisterFile.h"          // Person 3
#include "Memory.h"                // Person 3
#include "Screen.h"                // Person 4

class CPU {
private:
    bool halted;
    ProgramCounter pc;
    InstructionRegister ir;
    RegisterFile registers;
    InstructionDecoder decoder;
    InstructionExecutor executor;

public:
    CPU();

    void initialize(int startAddress);
    void step(Memory& memory, Screen& screen);
    void fetch(Memory& memory);
    bool validate() const;
    Instruction decode() const;
    ExecutionOutcome execute(const Instruction& instruction,
                             Memory& memory, Screen& screen);

    bool isHalted() const;
    ProgramCounter& getProgramCounter();
    InstructionRegister& getInstructionRegister();
    RegisterFile& getRegisterFile();
};
#endif