#ifndef SIMULATOREXCEPTION_H
#define SIMULATOREXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class SimulatorException : public exception {
private:
    string message;

public:
    SimulatorException(const string& message) : message(message) {}

    const char* what() const noexcept override {
        return message.c_str();
    }

    string getMessage() const {
        return message;
    }
};

#endif