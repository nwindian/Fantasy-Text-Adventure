#include "gold.h"
#include "../cursorSet/cursorSet.h"
#include "../clearGaps/clearGaps.h"
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

void gold()
{
    cursorSet(0, 25);
    srand(time(0));
    int goldCount = rand() % 30 + 20;
    std::cout << goldCount;
    std::cout << " gold has been added to your inventory";
    //addGold(goldCount);
    Sleep(800);
    clearGaps();
    return;

}
