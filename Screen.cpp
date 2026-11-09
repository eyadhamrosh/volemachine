#include "Screen.h"
#include <iostream>

Screen::Screen() : echo(true) {}

void Screen::print(char c)
{
    buffer += c;
    if (echo)
        std::cout << c;
}

void Screen::print(const std::string& text)
{
    buffer += text;
    if (echo)
        std::cout << text;
}

void Screen::clear()
{
    buffer.clear();
}

void Screen::setEcho(bool enabled)
{
    echo = enabled;
}

const std::string& Screen::getContents() const
{
    return buffer;
}