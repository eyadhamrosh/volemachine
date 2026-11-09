#include <iostream>
#include "InstructionExecutor.h"
#include "HexUtil.h"
#include "SimulatorException.h"
#include <cmath>

double InstructionExecutor::decodeFloat(int byte) {
    int sign = (byte >> 7) & 1;
    int exponent = ((byte >> 4) & 7) - 4;
    int mantissa = byte & 0xF;
    double value = std::ldexp(mantissa / 16.0, exponent);
    return sign ? -value : value;
}

int InstructionExecutor::encodeFloat(double value) {
    if (value == 0.0) return 0;
    int sign = value < 0 ? 1 : 0;
    double a = std::fabs(value);

    int e;
    double f = std::frexp(a, &e);
    int exponent = e + 4;
    int mantissa = static_cast<int>(f * 16);

    if (exponent > 7) { exponent = 7; mantissa = 15; }
    if (exponent < 0) return 0;
    return (sign << 7) | (exponent << 4) | mantissa;
}

ExecutionOutcome InstructionExecutor::execute(const Instruction& ins,
                                              RegisterFile& registers,
                                              ProgramCounter& pc,
                                              Memory& memory,
                                              Screen& screen) {
    int op = ins.getOpcode();
    int r  = ins.getOperand1();
    int xy = (ins.getOperand2() << 4) | ins.getOperand3();

    switch (op) {
        case 0x1:
            registers.write(r, memory.read(xy));
            break;

        case 0x2:
            registers.write(r, xy);
            break;

        case 0x3:
            memory.write(xy, registers.read(r));
            if (xy == 0)
                screen.print(HexUtil::toHex(registers.read(r), 2));
            break;

        case 0x4: {
            int src = ins.getOperand2();
            int dst = ins.getOperand3();
            registers.write(dst, registers.read(src));
            break;
        }

        case 0x5:
            registers.write(r, registers.read(ins.getOperand2()) + registers.read(ins.getOperand3()));
            break;

        case 0x6: {
            double a = decodeFloat(registers.read(ins.getOperand2()));
            double b = decodeFloat(registers.read(ins.getOperand3()));
            registers.write(r, encodeFloat(a + b));
            break;
        }

        case 0x7:
            registers.write(r, registers.read(ins.getOperand2()) | registers.read(ins.getOperand3()));
            break;

        case 0x8:
            registers.write(r, registers.read(ins.getOperand2()) & registers.read(ins.getOperand3()));
            break;

        case 0x9:
            registers.write(r, registers.read(ins.getOperand2()) ^ registers.read(ins.getOperand3()));
            break;

        case 0xA: {
            int steps = ins.getOperand3() % 8;
            int v = registers.read(r);
            v = ((v >> steps) | (v << (8 - steps))) & 0xFF;
            registers.write(r, v);
            break;
        }

        case 0xB: 
            if (registers.read(r) == registers.read(0)) {
                pc.setAddress(xy);
                return ExecutionOutcome::JUMPED;
            }
            break;

        case 0xC:   // C000 : halt
            return ExecutionOutcome::HALT;

        default:
            throw SimulatorException("Unknown opcode.");
    }
    return ExecutionOutcome::CONTINUE;
}