#include "../cursorSet/cursorSet.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
int optionSelector(int size, int dx, int dy)
{
    int y = dy;
    while (true)
    {
        cursorSet(dx, y);
        std::cout << "-->";
        switch(getch())
        {
            case 'w':
                cursorSet(dx, y);
                std::cout << "   ";
                --y;
                if (y < dy)
                {
                    y = size + dy - 1;
                }
                break;
            case 's':
                cursorSet(dx, y);
                std::cout << "   ";
                ++y;
                if (y > dy + size - 1)
                {
                    y = dy;
                }
                break;
            case 13:
                return y - dy;
//            default:
//                cursorSet(dx, dy + size + 1);
//                std::cout << "Invalid key";
//                Sleep(300);
//                cursorSet(dx, dy + size + 1);
//                std::cout << std::setw(11) << " ";
//                break;
        }
    }
}
