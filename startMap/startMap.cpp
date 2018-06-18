#include "startMap.h"
#include "../Stamina/Stamina.h"
#include "../Biome_Class/Biome_Class.h"
#include "../playerView/playerView.h"
#include "../displayMap/displayMap.h"
#include "../moving/moving.h"
#include "../cursorSet/cursorSet.h"
#include "../entityCheck/entityCheck.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <windows.h>

using std::cout;
using std::setw;
void startMap()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = false;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console,&lpCursor);
    srand(time(0));
    int x = 0;
    int y = 0;
    int biome = 0;
    int biomeRestrict[3] = {0};
    Stamina stamina;
    Biome maps[] = {Biome(0, 'F', 2), Biome(-1, 'T', 11), Biome(1, 'D', 14), Biome(0, 'M', 8)};
    playerView(maps[biome], x, y, stamina);
    displayMap(maps[biome].map, 2);

    while (true)
    {
        switch(biome)
        {
            case 0:
                while (biome == 0)
                {
                    playerView(maps[biome], x, y, stamina);
                    moving(x, y, biome, maps[biome], stamina, biomeRestrict);
                    if (x == 50)
                    {
                        if (biomeRestrict[0] != 1)
                        {
                            cursorSet(0, 25);
                            cout << "Story stuff, you shall not pass!";
                            Sleep(1000);
                            cursorSet(0, 25);
                            cout << setw(50) << " ";
                            --x;
                            stamina.increase();
                        }
                        else
                        {
                            maps[biome].map[y][x-1] =  maps[biome].getEntity(y, x-1);
                            biome = 2;
                            x = 0;
                            displayMap(maps[biome].map, 14);
                        }

                    }
                    if (y == 25)
                    {
                        if (biomeRestrict[1] != 1)
                        {
                            cursorSet(0, 25);
                            cout << "Story stuff, you shall not pass!";
                            Sleep(1000);
                            cursorSet(0, 25);
                            cout << setw(50) << " ";
                            --y;
                            stamina.increase();
                        }
                        else
                        {
                            maps[biome].map[y-1][x] =  maps[biome].getEntity(y-1, x);
                            biome = 1;
                            y = 0;
                            displayMap(maps[biome].map, 11);
                        }

                    }
                    if (x == -1)
                    {
                        if (biomeRestrict[2] != 1)
                        {
                            cursorSet(0, 25);
                            cout << "Story stuff, you shall not pass!";
                            Sleep(1000);
                            cursorSet(0, 25);
                            cout << setw(50) << " ";
                            ++x;
                            stamina.increase();
                        }
                        else
                        {
                            maps[biome].map[y][x+1] =  maps[biome].getEntity(y, x+1);
                            biome = 3;
                            x = 49;
                            displayMap(maps[biome].map, 8);
                        }

                    }
                    playerView(maps[biome], x, y, stamina);
                    entityCheck(maps[biome], x, y);
                }
                break;
            case 1:
                while (biome == 1)
                {
                    playerView(maps[biome], x, y, stamina);
                    moving(x, y, biome, maps[biome], stamina, biomeRestrict);
                    if (y == -1)
                    {
                        maps[biome].map[y+1][x] = maps[biome].getEntity(y+1, x);
                        biome = 0;
                        y = 24;
                        displayMap(maps[biome].map, 2);
                    }
                    playerView(maps[biome], x, y, stamina);
                    entityCheck(maps[biome], x, y);
                }
                break;
            case 2:
                while (biome == 2)
                {
                    playerView(maps[biome], x, y, stamina);
                    moving(x, y, biome, maps[biome], stamina, biomeRestrict);
                    if (x == -1)
                    {
                        maps[biome].map[y][x+1] =  maps[biome].getEntity(y, x+1);
                        biome = 0;
                        x = 49;
                        displayMap(maps[biome].map, 2);
                    }
                    playerView(maps[biome], x, y, stamina);
                    entityCheck(maps[biome], x, y);
                }
                break;
            case 3:
                while (biome == 3)
                {
                    playerView(maps[biome], x, y, stamina);
                    moving(x, y, biome, maps[biome], stamina, biomeRestrict);;
                    if (x == 50)
                    {
                        maps[biome].map[y][x-1] =  maps[biome].getEntity(y, x-1);
                        biome = 0;
                        x = 0;
                        displayMap(maps[biome].map, 2);
                    }
                    playerView(maps[biome], x, y, stamina);
                    entityCheck(maps[biome], x, y);
                }
                break;
        }

    }
}
