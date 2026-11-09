#include <iostream>
#include "Instruction.h"
#include "RegisterFile.h"
#include "ProgramCounter.h"
#include "Memory.h"
#include "Screen.h"
#include "ExecutionOutcome.h"
using namespace std;
#ifndef INSTRUCTION_EXECUTOR_H
#define INSTRUCTION_EXECUTOR_H

#include "Instruction.h"
#include "RegisterFile.h"
#include "ProgramCounter.h"
#include "Memory.h"
#include "Screen.h"
#include "ExecutionOutcome.h"

class InstructionExecutor {
private:
    static double decodeFloat(int byte);
    static int encodeFloat(double value);

public:
    ExecutionOutcome execute(const Instruction& instruction,
                             RegisterFile& registers,
                             ProgramCounter& pc,
                             Memory& memory,
                             Screen& screen);
};

#endif