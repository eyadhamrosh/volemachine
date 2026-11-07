#ifndef  PROGRAMCOUNTER_H
#define  PROGRAMCOUNTER_H
class ProgramCounter {
private:
    int address;
 
public:
    ProgramCounter();
 
    int getAddress() const;
    void setAddress(int addr);
    void advance(); 
};
#endif