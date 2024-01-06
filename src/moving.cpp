#include "../include/moving.h"
#include "../include/moveOptions.h"
#include "../include/Stamina.h"
#include "../include/cursorSet.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>

using std::cin;
using std::cout;
using std::setw;
void moving(int& x, int& y, int biome, Biome& map, Stamina& stamina, int biomeRestrict[])
{
    int allowed[4] = {0};
    moveOptions(x, y, biome, allowed);
    cin.clear();
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    double rest = 0;
    while (true)
    {
        char option = 'r';
        if (kbhit())
        {
            option = getch();
            rest = 0;
        }
        else
        {
            rest += .1;
        }
        switch (option)
        {
            case 'a':
                if (!stamina.check())
                {
                    cursorSet(0, 26);
                    cout << "You are out of stamina. Rest to regain.";
                    Sleep(300);
                    return;
                }
                if (allowed[0] == 1)
                {
                    --x;
                    stamina.decrease();
                }
                else
                {
                    cursorSet(0, 25);
                    cout << "You can't go here...";
                    Sleep(1000);
                    cursorSet(0, 25);
                    cout << setw(50) << " ";
                }
                return;
            case 'd':
                if (!stamina.check())
                {
                    cursorSet(0, 26);
                    cout << "You are out of stamina. Rest to regain.";
                    Sleep(300);
                    return;
                }
                if (allowed[1] == 1)
                {
                    ++x;
                    stamina.decrease();
                }
                else
                {
                    cursorSet(0, 25);
                    cout << "You can't go here...";
                    Sleep(1000);
                    cursorSet(0, 25);
                    cout << setw(50) << " ";
                }
                return;
            case 'w':
                if (!stamina.check())
                {
                    cursorSet(0, 26);
                    cout << "You are out of stamina. Rest to regain.";
                    Sleep(300);
                    return;
                }
                if (allowed[2] == 1)
                {
                    --y;
                    stamina.decrease();
                }
                else
                {
                    cursorSet(0, 25);
                    cout << "You can't go here...";
                    Sleep(1000);
                    cursorSet(0, 25);
                    cout << setw(50) << " ";
                }
                return;
            case 's':
                if (!stamina.check())
                {
                    cursorSet(0, 26);
                    cout << "You are out of stamina. Rest to regain.";
                    Sleep(300);
                    return;
                }
                if (allowed[3] == 1)
                {
                    ++y;
                    stamina.decrease();
                }
                else
                {
                    cursorSet(0, 25);
                    cout << "You can't go here...";
                    Sleep(1000);
                    cursorSet(0, 25);
                    cout << setw(50) << " ";
                }
                return;
            case 'r':
                if (rest > 3000)
                {
                    cursorSet(0, 26);
                    cout << setw(50) <<  " ";
                    cursorSet(0, 27);
                    stamina.increase();
                    stamina.display();
                    rest = 0;
                }

                break;
            case 'p':
                for (int i = 0; i < 3; ++i)
                {
                    biomeRestrict[i] = 1;
                }
                return;
            default:
                cursorSet(0, 25);
                cout << "Invalid Key";
                Sleep(500);
                cursorSet(0, 25);
                cout << setw(50) << " ";
                break;

        }
    }

    return;
}
