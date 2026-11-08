#ifndef MACHINEDISPLAY_H
#define MACHINEDISPLAY_H

#include <string>
#include "Memory.h"
#include "CPU.h"
#include "Screen.h"

using namespace std;

class MachineDisplay {
public:
    MachineDisplay() = default;

    void showMenu() {
    }

    void showMemoryMatrix(const Memory& memory) {
    }

    void showCPUState(const CPU& cpu) {
    }

    void showScreen(const Screen& screen) {
    }

    void showMachineState(const CPU& cpu, const Memory& memory, const Screen& screen) {
    }

    void showMessage(const string& message) {
    }

    void showError(const string& message) {
    }
};

#endif