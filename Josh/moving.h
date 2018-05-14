#ifndef MOVING
#define MOVING

#include <conio.h>
#include <iomanip>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77



void moving(int& x, int& y, int biome, Biome& map, Stamina& stamina, int biomeRestrict[])
{
    int allowed[4] = {0};
    moveOptions(x, y, biome, allowed);
    cin.clear();
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    char obj = getch();
    if (obj == 'r' )
    {
        cursorSet(0, 26);
        cout << setw(50) <<  " ";
        Sleep(500);
        stamina.increase();
    }
    else if (obj == 'p')
    {
        for (int i = 0; i < 3; ++i)
        {
            biomeRestrict[i] = 1;
        }
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
                    cursorSet(0, 25);
                    cout << "You can't go here...";
                    Sleep(1000);
                    cursorSet(0, 25);
                    cout << setw(50) << " ";
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
                    cursorSet(0, 25);
                    cout << "You can't go here...";
                    Sleep(1000);
                    cursorSet(0, 25);
                    cout << setw(50) << " ";
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
                    cursorSet(0, 25);
                    cout << "You can't go here...";
                    Sleep(1000);
                    cursorSet(0, 25);
                    cout << setw(50) << " ";
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
                    cursorSet(0, 25);
                    cout << "You can't go here...";
                    Sleep(1000);
                    cursorSet(0, 25);
                    cout << setw(50) << " ";
                }
                break;
        }
    }
    return;
}

#endif // MOVING
