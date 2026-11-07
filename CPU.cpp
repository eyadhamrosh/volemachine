#include<iostream>
using namespace std;
#include "CPU.h"
#include "SimulatorException.h"   

CPU::CPU() : halted(false) {}

void CPU::initialize(int startAddress) {
    pc.setAddress(startAddress);
    halted = false;
}

void CPU::fetch(Memory& memory) {
    // reads 2 cells (4 hex digits) starting at the PC address
    ir.setValue(memory.readWord(pc.getAddress()));
}

bool CPU::validate() const {
    return decoder.isValid(ir.getValue());
}

Instruction CPU::decode() const {
    return decoder.decode(ir.getValue());
}

ExecutionOutcome CPU::execute(const Instruction& instruction,
                              Memory& memory, Screen& screen) {
    return executor.execute(instruction, registers, pc, memory, screen);
}

void CPU::step(Memory& memory, Screen& screen) {
    if (halted) return;

    fetch(memory);

    if (!validate())
        throw SimulatorException("Invalid instruction: " + ir.getValue());

    Instruction instr = decode();
    ExecutionOutcome outcome = execute(instr, memory, screen);

    switch (outcome) {
        case ExecutionOutcome::CONTINUE: pc.advance(); break;
        case ExecutionOutcome::JUMPED:   break;   // executor already set the PC
        case ExecutionOutcome::HALT:     halted = true; break;
    }
}

bool CPU::isHalted() const {
    return halted;
}

ProgramCounter& CPU::getProgramCounter() {
    return pc;
}

InstructionRegister& CPU::getInstructionRegister() {
    return ir;
}

RegisterFile& CPU::getRegisterFile() {
    return registers;
}