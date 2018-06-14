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
