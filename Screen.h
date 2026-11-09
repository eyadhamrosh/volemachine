#ifndef SCREEN_H
#define SCREEN_H

#include <string>

class Screen {
private:
    std::string buffer;
    bool echo;

public:
    Screen();

    void print(char c);
    void print(const std::string& text);
    void clear();
    void setEcho(bool enabled);

    const std::string& getContents() const;
};

#endif