#ifndef SIMULATORMENU_H
#define SIMULATORMENU_H

#include <iostream>
#include <string>
#include "VoleMachine.h"
#include "MachineDisplay.h"

using namespace std;

class SimulatorMenu {
private:
    VoleMachine* machine;
    MachineDisplay* display;

    void promptLoadProgram() {
        string fileName, startAddress;
        cout << "Enter file name/path: ";
        getline(cin, fileName);
        cout << "Enter start address (Hex, e.g., 00): ";
        getline(cin, startAddress);

        int loadedCount = machine->loadProgram(fileName, startAddress);
        display->showMessage("Program loaded successfully. Instructions count: " + to_string(loadedCount));
    }

    void promptEditRegister() {
        string index, value;
        cout << "Enter register index (0-F): ";
        getline(cin, index);
        cout << "Enter new value (Hex): ";
        getline(cin, value);

        machine->editRegister(index, value);
        display->showMessage("Register updated successfully.");
    }

    void promptEditMemory() {
        string address, value;
        cout << "Enter memory address (Hex, e.g., 0A): ";
        getline(cin, address);
        cout << "Enter value (Hex, e.g., 1A): ";
        getline(cin, value);

        machine->editMemory(address, value);
        display->showMessage("Memory cell updated successfully.");
    }

    void promptExecute() {
        machine->step();
        display->showMachineState(machine->getCpu(), machine->getMemory(), machine->getScreen());
    }

    void runStepByStep() {
        while (!machine->isProgramFinished()) {
            promptExecute();
            waitForEnter();
        }
    }

    void waitForEnter() {
        cout << "Press Enter to continue to the next step...";
        cin.get();
    }

    bool promptExitOrLoadAnother() {
        string response;
        cout << "Do you want to load another program? (y/n): ";
        getline(cin, response);
        return (response == "y" || response == "Y");
    }

public:
    SimulatorMenu(VoleMachine* machine, MachineDisplay* display) 
        : machine(machine), display(display) {
        if (machine) {
            machine->getScreen().setEcho(false);
        }
    }

    void start() {
        bool running = true;
        while (running) {
            display->showMenu();
            cout << "Choose an option: ";
            int choice;
            cin >> choice;
            cin.ignore();

            handleMenuChoice(choice);

            if (choice == 6) {
                running = false;
            }
        }
    }

    void handleMenuChoice(int choice) {
        try {
            switch (choice) {
                case 1:
                    promptLoadProgram();
                    break;
                case 2:
                    promptEditRegister();
                    break;
                case 3:
                    promptEditMemory();
                    break;
                case 4:
                    promptExecute();
                    break;
                case 5:
                    machine->runAll();
                    display->showMachineState(machine->getCpu(), machine->getMemory(), machine->getScreen());
                    break;
                case 6:
                    display->showMessage("Exiting Simulator. Goodbye!");
                    break;
                default:
                    display->showError("Invalid choice! Please try again.");
            }
        } catch (const exception& e) {
            display->showError(e.what());
        }
    }
};

#endif