#include "MachineDisplay.h"
#include <iostream>
#include <iomanip>

using namespace std;

void MachineDisplay::showMessage(const string& message) const
{
    cout << message << "\n";
}

void MachineDisplay::showError(const string& message) const
{
    cout << "[Error] " << message << "\n";
}

void MachineDisplay::showCPUState(const CPU& cpu) const
{
    cout << "\n--- CPU STATE ---\n";
    cout << "PC : " << hex << uppercase << setw(2) << setfill('0')
         << cpu.getProgramCounter().getAddress() << " | ";
    cout << "IR : " << cpu.getInstructionRegister().getValue() << "\n";

    cout << "Registers (R0 - RF):\n";
    for (int i = 0; i < 16; ++i)
    {
        cout << "R" << hex << uppercase << i << ": "
             << setw(2) << setfill('0') << cpu.getRegisterFile().read(i)
             << "   ";
        if ((i + 1) % 4 == 0)
            cout << "\n";
    }
    cout << dec << setfill(' ');
}

void MachineDisplay::showMemory(const Memory& memory) const
{
    cout << "\n--- MEMORY ---\n    ";
    for (int col = 0; col < 16; ++col)
        cout << hex << uppercase << col << "  ";
    cout << "\n";

    for (int row = 0; row < 16; ++row)
    {
        cout << hex << uppercase << row << "0: ";
        for (int col = 0; col < 16; ++col)
            cout << setw(2) << setfill('0') << memory.readCell(row * 16 + col)
                 << " ";
        cout << "\n";
    }
    cout << dec << setfill(' ');
}

void MachineDisplay::showScreen(const Screen& screen) const
{
    cout << "\n--- SCREEN ---\n" << screen.getContents() << "\n";
}

void MachineDisplay::showMachineState(const CPU& cpu, const Memory& memory,
                                      const Screen& screen) const
{
    showCPUState(cpu);
    showMemory(memory);
    showScreen(screen);
}