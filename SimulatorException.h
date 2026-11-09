#ifndef SIMULATOR_EXCEPTION_H
#define SIMULATOR_EXCEPTION_H

#include <exception>
#include <string>

class SimulatorException : public std::exception {
private:
    std::string message;

public:
    explicit SimulatorException(const std::string& msg);

    const char* what() const noexcept override;
};

#endif