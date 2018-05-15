#ifndef MAP
#define MAP

void startMap()
{
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
    Biome maps[] = {Biome(0, 'F'), Biome(-1, 'T'), Biome(1, 'D'), Biome(0, 'M')};
    playerView(maps[biome], x, y, stamina);
    displayMap(maps[biome].map);

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
                            displayMap(maps[biome].map);
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
                            displayMap(maps[biome].map);
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
                            displayMap(maps[biome].map);
                        }

                    }
                    if (maps[biome].getEntity(y, x) == 'C')
                    {
                       cave(maps[biome], y, x);
                    }
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
                        displayMap(maps[biome].map);
                    }
                    if (maps[biome].getEntity(y, x) == 'C')
                    {
                       cave(maps[biome], y, x);
                    }
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
                        displayMap(maps[biome].map);
                    }
                    if (maps[biome].getEntity(y, x) == 'C')
                    {
                       cave(maps[biome], y, x);
                    }
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
                        displayMap(maps[biome].map);
                    }
                    if (maps[biome].getEntity(y, x) == 'C')
                    {
                       cave(maps[biome], y, x);
                    }
                }
                break;
        }

    }
}

#endif // MAP
