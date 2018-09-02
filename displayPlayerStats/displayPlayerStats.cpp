#include "displayPlayerStats.h"
#include "../Player_Combat_Weapon/include/Player_Class.h"
#include "../player/player.h"
#include "../cursorSet/cursorSet.h"
#include <iostream>
#include <windows.h>

using namespace player;

void displayPlayerStats()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cursorSet(100, 0);
    std::cout << "Health: " << players.getHealth() << "/10"; //<< players.getMaxHealth();
    cursorSet(100, 1);
    std::cout << "Strength: " << players.getStrength();
    cursorSet(100, 2);
    std::cout << "Attack Speed: " << players.getSpeed();
    cursorSet(100, 3);
    std::cout << "Level: " << players.getLevel();
    cursorSet(100, 4);
    std::cout << "Experience: " << players.getCExp() << "/" << players.getMaxExp();
    cursorSet(100, 5);
    return;

}
