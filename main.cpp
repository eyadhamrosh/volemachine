#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Screen {
private:
    vector<string> output;
    bool echo;

public:
    Screen() : echo(true) {}

    void print(const string& value) {
        output.push_back(value);
        if (echo) {
            cout << value << endl;
        }
    }

    vector<string> getOutput() const {
        return output;
    }

    void setEcho(bool enable) {
        echo = enable;
    }

    bool getEcho() const {
        return echo;
    }
};

#endif