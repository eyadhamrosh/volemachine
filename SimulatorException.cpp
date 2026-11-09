#include "SimulatorException.h"

SimulatorException::SimulatorException(const std::string& msg)
    : message(msg) {}

const char* SimulatorException::what() const noexcept
{
    return message.c_str();
}