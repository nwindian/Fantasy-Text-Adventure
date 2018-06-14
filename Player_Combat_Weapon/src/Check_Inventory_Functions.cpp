#include <iostream>
#include "rlutil.h"
#include "Check_Inventory_Functions.h"

int getInventory()
{
    int moveCount = 0;
    int x = 20;
    int y = 2;
    rlutil::cls();
    std::cout << "Would you like to change your weapon or heal?????" << std::endl;
    std::cout << "1) Food(healing) " << std::endl << "2) Weapons";
    while (true) {
        rlutil::locate(x,y);
        rlutil::hidecursor();
        std::cout << " <--";
        if (!kbhit())
        {
            char k = getch(); // Get character
            rlutil::locate(x,y); std::cout << "     "; // Erase player
            if (k == 'w')
            {
                if (y == 2)
                {
                    moveCount = 1;
                    y = 3;
                }
                else
                {
                    moveCount = 0;
                    y = 2;
                }
            }
            else if (k == 's')
            {
                if (y == 3)
                {
                    moveCount = 0;
                    y = 2;
                }
                else
                {
                    moveCount = 1;
                    y = 3;
                }
            }
            else if (k == ' ')
            {
                rlutil::cls();
                return moveCount;
            }
        }
    }
}

int getFromInventory(Player_Class &play)
{
    int moveCount = 0;
    int x = 20;
    int y = 1;
    std::cout << " Which Inventory do you want to look at?" << std::endl;
    int inv = getInventory();
    if (inv == 0)
    {
        for(int i = 0; i < play.foodInventory.size(); ++i)
        {
            std::cout << play.foodInventory[i].getName() << std::endl;
        }
        while (true)
        {
            rlutil::locate(x,y);
            rlutil::hidecursor();
            std::cout << " <--";
            if (!kbhit())
            {
                char k = getch(); // Get character
                rlutil::locate(x,y); std::cout << "     "; // Erase player
                if (k == 'w')
                {
                    if (y == 1)
                    {
                        moveCount = play.foodInventory.size();
                        y = play.foodInventory.size();
                    }
                    else
                    {
                        --moveCount;
                        y = y - 1;
                    }
                }
                else if (k == 's')
                {
                    if (y == play.foodInventory.size())
                    {
                        moveCount = 0;
                        y = 1;
                    }
                    else
                    {
                        ++moveCount;
                        y = y + 1;
                    }
                }
                else if (k == ' ')
                {
                    rlutil::cls();
                    return moveCount;
                }
            }
        }
    }
}
