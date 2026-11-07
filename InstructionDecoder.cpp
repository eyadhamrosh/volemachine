#include <iostream>
using namespace std;
#include "InstructionDecoder.h"

int InstructionDecoder::hexToInt(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return -1;
}

bool InstructionDecoder::isValid(const std::string& hexCode) const {
    if (hexCode.size() != 4) return false;

    for (char c : hexCode)
        if (hexToInt(c) < 0) return false;

    int opcode = hexToInt(hexCode[0]);
    return opcode >= 1 && opcode <= 12;   // 1..C
}

Instruction InstructionDecoder::decode(const std::string& hexCode) const {
    return Instruction(hexToInt(hexCode[0]),
                       hexToInt(hexCode[1]),
                       hexToInt(hexCode[2]),
                       hexToInt(hexCode[3]));
}