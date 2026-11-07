#ifndef InstructionDecoder_H
#define InstructionDecoder_H
#include <string>
#include "Instruction.h"  
 
class InstructionDecoder {
private:
    static int hexToInt(char c);
 
public:
    bool isValid(const std::string& hexCode) const;
    Instruction decode(const std::string& hexCode) const;
};
#endif