#ifndef SIMULATOR_MENU_H
#define SIMULATOR_MENU_H

#include <string>
#include "VoleMachine.h"
#include "MachineDisplay.h"

class SimulatorMenu {
private:
    VoleMachine machine;
    MachineDisplay display;
    bool running;
    bool programLoaded;

    bool readLine(const std::string& prompt, std::string& out);
    void showMainMenu() const;

    void loadProgram();
    void runAll();
    void runStepByStep();
    void showState();
    void promptExitOrLoadAnother();

public:
    SimulatorMenu();
    void start();
};

#endif