#include "getTreasure.h"
#include "../gold/gold.h"
#include "../clearGaps/clearGaps.h"
#include "../cursorSet/cursorSet.h"
#include "../optionSelector/optionSelector.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void getTreasure()
{
    clearGaps();
    cursorSet(0, 25);
    std::cout << "You discovered a treasure chest!" << std::endl;
    std::cout << "Would you like to open it?" << std::endl;
    std::cout << "    Yes" << std::endl;
    std::cout << "    No" << std::endl;
    if (!optionSelector(2, 0, 27))
    {
        clearGaps();
        cursorSet(0, 25);
        srand(time(0));
        int num = 0; //rand() % 4;
        switch (num)
        {
            case 0:
                gold();
                break;
            case 1:
                //weapon();
                break;
            case 2:
                //scroll();
                break;
            case 3:
                //armor();
                break;
        }
    }
    clearGaps();
    return;
}

