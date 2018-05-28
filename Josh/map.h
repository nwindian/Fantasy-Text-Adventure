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

char entityCheck(Biome& biome, int x, int y)
{
    switch (biome.getEntity(y, x))
    {
        case 'C':
            cave(biome, y, x);
            break;
        case 'T':
            //getTreasure();
            break;
        case 'M':
            //monster stuff
            break;
        case 'V':
            village();
            for (int i = 0; i < 6; ++i)
            {
                cursorSet(0, 25 + i);
                cout << setw(50) << " ";
            }
            break;
    }
}

void village()
{
    cursorSet(0, 27);
    cout << setw(50) << " ";
    cursorSet(0, 28);
    cout << setw(50) << " ";
    cursorSet(0, 25);
    cout << "Would you like to enter the village? (Y)es (N)o";
    do
    {
        char responce = getch();
        if (responce == 'y')
        {
            cursorSet(0, 25);
            cout << setw(50) << " ";
            cursorSet(0, 25);
            cout << "Where would you like to go?";
            cursorSet(0, 26);
            cout << "(1) Weapon and Armor Smith\n"
                 << "(2) Food Shop\n"
                 << "(3) Scroll shop\n"
                 << "(4) Explore\n"
                 << "(5) Leave";
                 cin.get();
                 return;

        }
        else if (responce == 'n')
        {
            cursorSet(0, 26);
            cout << setw(30) << left << "Very well";
            cin.get();
            return;
        }
    } while (true);
}

void getTreasure()
{
    string loot;
    int goldCount = 0;
    int num = rand() % 1121;
    if (num > 599)
    {
        if (num < 840)
        {
            //foodObj = std::unique_ptr<Food>(new Food());
            //loot = foodObj->foodName;
        }
        else if (num < 960)
        {

            //goldNum = (rand() % 20 + 30);
            loot = "is gold";
        }
        else if (num < 1000)
        {

            loot = "is a weapon";
        }
        else if (num < 1080)
        {

            loot = "is a scroll";
        }
        else if (num == 1120)
        {
            //caveIn
        }
        else
        {

            loot = "is armor";
        }
    }
    else
    {
        loot = "nothing";
    }
}


#endif // MAP
