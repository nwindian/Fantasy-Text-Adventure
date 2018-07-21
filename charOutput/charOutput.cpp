#include <iostream>
#include <windows.h>

void charOutput(char ch, int color)
{
    if (ch == '\'')
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    std::cout << ch << " ";
    return;
}
