#include <iostream>
#include "../rlutil.h"
#include "Check_Inventory_Functions.h"
#include "Show_Health.h"


int getInventory(Player_Class & player, Monster & enemy, int h, int e)
{
    int moveCount = 0;
    int x = 20;
    int y = 2;
    rlutil::cls();
    showHealth(player, enemy,h,e);
    rlutil::locate(1,1); std::cout << "Weapon or heal?" << std::endl;
    std::cout << "1) Food / healing" << std::endl << "2) Weapons" << std::endl << "3) Armor";
    rlutil::locate(40,3); std::cout << "**Press b to go back or Enter to select." << std::endl;
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
                    moveCount = 2;
                    y = 4;
                }
                else
                {
                    --moveCount;
                    y = y - 1;
                }
            }
            else if (k == 's')
            {
                if (y == 4)
                {
                    moveCount = 0;
                    y = 2;
                }
                else
                {
                    ++moveCount;
                    y = y + 1;
                }
            }
            else if (k == '\r')
            {
                rlutil::cls();
                return moveCount;
            }
            else if (k =='b')
            {
                rlutil::cls();
                return -1;
            }
        }
    }
}

int getFromInventoryW(Player_Class &play)
{
    bool repeatFromB = true;
    int moveCount = 0;
    int x = 30;
    int y = 1;
    play.cycle_weapon();
    rlutil::locate(40,3); std::cout << "**Press b to go back or Enter to select." << std::endl;
    while (true)
    {
        rlutil::locate(x,y);
        rlutil::hidecursor();
        std::cout << " <--";
        if (!kbhit())
        {
            char k = getch(); // Get character
            rlutil::locate(x,y); std::cout << "         "; // Erase player
            if (k == 'w')
            {
                if (y == 1)
                {
                    moveCount = play.Wget_size();
                    y = play.Wget_size();
                }
                else
                {
                    --moveCount;
                    y = y - 1;
                }
            }
            else if (k == 's')
            {
                if (y == play.Wget_size())
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
            else if (k == '\r')
            {
                rlutil::cls();
                return moveCount;
            }
            else if (k == 'b')
            {
                rlutil::cls();
                return -1;
                break;
            }
        }
    }
}



int getFromInventoryF(Player_Class &play)
{
    bool repeatFromB = true;
    int moveCount = 0;
    int x = 30;
    int y = 1;
    play.cycle_food();
    rlutil::locate(40,3); std::cout << "**Press b to go back or Enter to select." << std::endl;
    while (true)
    {
        rlutil::locate(x,y);
        rlutil::hidecursor();
        std::cout << "   <--";
        if (!kbhit())
        {
            char k = getch(); // Get character
            rlutil::locate(x,y); std::cout << "       "; // Erase player
            if (k == 'w')
            {
                if (y == 1)
                {
                    moveCount = play.Fget_size();
                    y = play.Fget_size();
                }
                else
                {
                    --moveCount;
                    y = y - 1;
                }
            }
            else if (k == 's')
            {
                if (y == play.Fget_size())
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
            else if (k == '\r')
            {
                rlutil::cls();
                return moveCount;
            }
            else if (k == 'b')
            {
                rlutil::cls();
                return -1;
                break;
            }
        }
    }
}

int getFromInventoryA(Player_Class &play)
{
    bool repeatFromB = true;
    int moveCount = 0;
    int x = 30;
    int y = 1;
    play.cycle_armor();
    rlutil::locate(40,3); std::cout << "**Press b to go back or Enter to select." << std::endl;
    while (true)
    {
        rlutil::locate(x,y);
        rlutil::hidecursor();
        std::cout << "   <--";
        if (!kbhit())
        {
            char k = getch(); // Get character
            rlutil::locate(x,y); std::cout << "       "; // Erase player
            if (k == 'w')
            {
                if (y == 1)
                {
                    moveCount = play.Aget_size();
                    y = play.Aget_size();
                }
                else
                {
                    --moveCount;
                    y = y - 1;
                }
            }
            else if (k == 's')
            {
                if (y == play.Aget_size())
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
            else if (k == '\r')
            {
                rlutil::cls();
                return moveCount;
            }
            else if (k == 'b')
            {
                rlutil::cls();
                return -1;
                break;
            }
        }
    }
}

