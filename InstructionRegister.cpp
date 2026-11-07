#include<iostream>
using namespace std;
#include "InstructionRegister.h"

InstructionRegister::InstructionRegister() : value("0000") {}

std::string InstructionRegister::getValue() const {
    return value;
}

void InstructionRegister::setValue(const std::string& v) {
    value = v;
}