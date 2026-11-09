#include "SimulatorMenu.h"
#include "SimulatorException.h"
#include "HexUtil.h"
#include <iostream>

using namespace std;

SimulatorMenu::SimulatorMenu() : running(true), programLoaded(false) {}

// Returns false when the input stream has ended (EOF).
bool SimulatorMenu::readLine(const string& prompt, string& out)
{
    cout << prompt;
    if (!getline(cin, out))
    {
        running = false;
        return false;
    }
    return true;
}

void SimulatorMenu::showMainMenu() const
{
    cout << "\n===== VOLE MACHINE SIMULATOR =====\n"
         << "1. Load program from file\n"
         << "2. Run all\n"
         << "3. Run step by step\n"
         << "4. Show machine state\n"
         << "0. Exit\n";
}

void SimulatorMenu::start()
{
    while (running)
    {
        showMainMenu();

        string choice;
        if (!readLine("Choice: ", choice))
            break;

        try
        {
            if (choice == "1")      loadProgram();
            else if (choice == "2") runAll();
            else if (choice == "3") runStepByStep();
            else if (choice == "4") showState();
            else if (choice == "0") running = false;
            else display.showError("Invalid choice, enter 0-4.");
        }
        catch (const SimulatorException& e)
        {
            display.showError(e.what());
        }
    }

    display.showMessage("Goodbye.");
}

void SimulatorMenu::loadProgram()
{
    string fileName, startText;
    if (!readLine("File name: ", fileName)) return;
    if (!readLine("Start address (hex, 00-FF): ", startText)) return;

    int start = parseHex(startText, 0, 255, "start address");
    machine.loadProgram(fileName, start);
    programLoaded = true;
    display.showMessage("Program loaded.");
}

void SimulatorMenu::runAll()
{
    if (!programLoaded)
    {
        display.showError("Load a program first.");
        return;
    }

    machine.runAll();
    display.showMachineState(machine.getCPU(), machine.getMemory(),
                             machine.getScreen());
}

void SimulatorMenu::runStepByStep()
{
    if (!programLoaded)
    {
        display.showError("Load a program first.");
        return;
    }

    string dummy;
    while (!machine.getCPU().isHalted())
    {
        machine.step();
        display.showMachineState(machine.getCPU(), machine.getMemory(),
                                 machine.getScreen());

        if (machine.getCPU().isHalted())
            break;
        if (!readLine("Press Enter for next instruction (q to stop): ", dummy)
            || dummy == "q")
            return;
    }
    display.showMessage("Program halted.");
}

void SimulatorMenu::showState()
{
    display.showMachineState(machine.getCPU(), machine.getMemory(),
                             machine.getScreen());
}

void SimulatorMenu::promptExitOrLoadAnother()
{
    string answer;
    if (!readLine("Load another program? (y/n): ", answer))
        return;

    if (answer == "y" || answer == "Y")
        loadProgram();
    else
        running = false;
}