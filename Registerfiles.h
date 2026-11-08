#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class RegisterFile {
    private:
        vector<string> registers;

    public:
        RegisterFile(int size = 16);
        string getRegister(int index) const;
        void setRegister(int index, const string& value);
        void display() const;
};

#endif