#include <iostream>
#include <iomanip>
#include <limits>
#include "rlutil.h"
#include "Menu_Function.h"

int menu()
{
    rlutil::setColor(2);
    rlutil::saveDefaultColor();
    int moveCount = 1;
    int x = 3;
    int y = 3;
    int choice;
    bool repeatOne = true;
    rlutil::setColor(7);
    for (int i = 0; i < 39; ++i)
    {
        rlutil::locate(i+1,1); std::cout << "-";
    }
    for(int i = 2; i < 4; ++i)
    {
        rlutil::locate(40,i); std::cout << "|";
    }
    for (int i = 0; i < 39; ++i)
    {
        rlutil::locate(i+1,4); std::cout << "-";
    }
    rlutil::resetColor();
    rlutil::locate(1,2);std::cout << " Fight || Inventory || Escape " <<  std::endl;
            while (true)
            {
                rlutil::locate(x,y);
                rlutil::hidecursor();
                rlutil::resetColor();
                rlutil::setColor(7);
                std::cout << "^^^";
                if (!kbhit())
                {
                    char k = getch(); // Get character
                    rlutil::locate(x,y); std::cout << "     "; // Erase player
                    if (k == 'd')
                    {
                        if (x == 25)
                        {
                            moveCount = 1;
                            x = 3;
                        }
                        else
                        {
                            ++moveCount;
                            x = x + 11;
                        }
                    }
                    else if (k == 'a')
                    {
                        if (x == 3)
                        {
                            moveCount = 3;
                            x = 25;
                        }
                        else
                        {
                            --moveCount;
                            x = x - 11;
                        }
                    }
                    else if (k == '\r')
                    {
                        rlutil::resetColor();
                        return moveCount;
                    }
                }
            }
}
