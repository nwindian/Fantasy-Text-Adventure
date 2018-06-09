#ifndef CHECK_INVENTORY_FUNCTIONS_H_INCLUDED
#define CHECK_INVENTORY_FUNCTIONS_H_INCLUDED
#include "Player_Class.h"

int getInventory()
{
    int x = 15;
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
                    moveCount = play.moveList.size();
                    y = 3;
                }
                else
                {
                    y = 2;
                }
            }
            else if (k == 's')
            {
                if (y == 3)
                {
                    y = 2;
                }
                else
                {
                    y = 3;
                }
            }
            else if (k == ' ')
            {
                return moveCount;
            }
            else if (k == 'b')
            {
                rlutil::cls();
                return -1;
            }
        }
    }
}


#endif // CHECK_INVENTORY_FUNCTIONS_H_INCLUDED
