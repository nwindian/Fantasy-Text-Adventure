#include "Stamina.h"
#include <iostream>
#include <windows.h>

bool Stamina::check()
{
    if (staminaAr[0] == 0)
    {
        return false;
    }
    return true;
}

void Stamina::increase()
{
    for (int i = 0; i < 5; ++i)
    {
        if (staminaAr[i] != 2)
        {
            ++staminaAr[i];
            return;
        }
    }
}

void Stamina::decrease()
{
    for (int i = 4; i > -1; --i)
    {
        if (staminaAr[i] != 0)
        {
            --staminaAr[i];
            return;
        }
    }
}

void Stamina::display()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    std::cout << "Stamina\n";
    for (int i = 0; i < 5; ++i)
    {
        switch (staminaAr[i])
        {
        case 2:
            std::cout << "[||]";
            break;
        case 1:
            std::cout << "[| ]";
            break;
        case 0:
            std::cout << "[  ]";
            break;
        }

    }
}
