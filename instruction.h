#define INSTRUCTION_H
#ifndef INSTRUCTION_H

class Instruction {
private:
    int op;
    int r;
    int x;
    int y;

public:
    Instruction(int o = 0, int r1 = 0, int p2 = 0, int p3 = 0) {
        op = o;

        r = r1;
        x = p2;

        y = p3;
    }

    int getOpcode() const {
        return op;
    }

    int getOperand1() const {
        return r;
    }

    int getOperand2() const {
        return x;
    }

    int getOperand3() const {


        return y;
    }

    int getAddress() const {
        return (x<< 4) | y;
    }
};

#endif