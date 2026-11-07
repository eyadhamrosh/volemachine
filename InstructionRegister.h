#ifndef InstructionRegister_H
#define InstructionRegister_H
#include <string>
class InstructionRegister {
private:
    std::string value;
 
public:
    InstructionRegister();
 
    std::string getValue() const;
    void setValue(const std::string& v);
};
#endif