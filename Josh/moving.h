#ifndef MOVING
#define MOVING

#include <conio.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77



void moving(int& x, int& y, int biome, Biome& map, Stamina& stamina)
{
    int allowed[4] = {0};
    moveOptions(x, y, biome, allowed);
    cin.clear();
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    if (getch() == 'r' )
    {
        Sleep(500);
        stamina.increase();
    }
    else
    {
        if (!stamina.check())
        {
            cursorSet(0, 26);
            cout << "You are out of stamina. Press R to rest.";
            return;
        }
        switch (getch())
        {
            case KEY_LEFT:
                if (allowed[0] == 1)
                {
                    --x;
                    stamina.decrease();
                }
                else
                {
                    cout << "You can't go here...";
                    Sleep(500);
                    for (int i = 0; i < 14; ++i)
                    {
                        cout << map.map[y + 1][x + i] << " ";
                    }

                }
                break;
            case KEY_RIGHT:
                if (allowed[1] == 1)
                {
                    ++x;
                    stamina.decrease();
                }
                else
                {
                    cout << "You can't go here...";
                    Sleep(500);
                    for (int i = 0; i < 14; ++i)
                    {
                        cout << map.map[y + 1][x + i] << " ";
                    }

                }
                break;
            case KEY_UP:
                if (allowed[2] == 1)
                {
                    --y;
                    stamina.decrease();
                }
                else
                {
                    cout << "You can't go here...";
                    Sleep(500);
                    for (int i = 0; i < 14; ++i)
                    {
                        cout << map.map[y + 1][x + i] << " ";
                    }

                }
                break;
            case KEY_DOWN:
                if (allowed[3] == 1)
                {
                    ++y;
                    stamina.decrease();
                }
                else
                {
                    cout << "You can't go here...";
                    Sleep(500);
                    for (int i = 0; i < 14; ++i)
                    {
                        cout << map.map[y + 1][x + i] << " ";
                    }

                }
                break;
        }
    }
    return;
}

#endif // MOVING
