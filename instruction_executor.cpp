#include "instruction_executor.h"
#include "RegisterFile.h"
#include "Memory.h"
#include "ProgramCounter.h"
#include "Screen.h"

ExecutionOutcome InstructionExecutor::executeInstruction(
    const Instruction& instr,
    RegisterFile& registers,
    ProgramCounter& pc,
    Memory& memory,
    Screen& screen) {
    
    int op = instr.getOpcode();
    int r = instr.getOperand1();
    int address = instr.getAddress();

    switch (op) {
        case 1: {
            int val = memory.getCell(address);
            registers.setRegister(r, val);
            break;
        }
            
        case 2: {
            int val = instr.getAddress();
            registers.setRegister(r, val);
            break;
        }
            
        case 3: {
            int val = registers.getRegister(r);
            memory.setCell(address, val);
            break;
        }
            
        case 4: {
            int targetReg = instr.getOperand2();
            int val = registers.getRegister(targetReg);
            registers.setRegister(r, val);
            break;
        }
            
        case 5: {
            int r2 = instr.getOperand2();
            int r3 = instr.getOperand3();
            int sum = registers.getRegister(r2) + registers.getRegister(r3);
            registers.setRegister(r, sum);
            break;
        }
            
        case 11: {
            int val = registers.getRegister(r);
            if (val == registers.getRegister(0)) {
                pc.setPC(address);
                return ExecutionOutcome::JUMPED;
            }
            break;
        }
            
        case 12: {
            return ExecutionOutcome::HALT;
        }
            
        default:
            break;
    }

    return ExecutionOutcome::CONTINUE;
}