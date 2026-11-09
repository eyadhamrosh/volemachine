#ifndef MACHINE_DISPLAY_H
#define MACHINE_DISPLAY_H

#include <string>
#include "CPU.h"
#include "Memory.h"
#include "Screen.h"

class MachineDisplay {
public:
    void showMessage(const std::string& message) const;
    void showError(const std::string& message) const;

    void showCPUState(const CPU& cpu) const;
    void showMemory(const Memory& memory) const;
    void showScreen(const Screen& screen) const;
    void showMachineState(const CPU& cpu, const Memory& memory,
                          const Screen& screen) const;
};

#endif