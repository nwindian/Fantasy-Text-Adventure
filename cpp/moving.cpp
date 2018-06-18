#include <conio.h>
#include <iomanip>

void moving(int& x, int& y, int biome, Biome& map, Stamina& stamina, int biomeRestrict[])
{
    int allowed[4] = {0};
    moveOptions(x, y, biome, allowed);
    cin.clear();
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    char obj = getch();

        switch (obj)
        {
            case 'a':
                if (!stamina.check())
                {
                    cursorSet(0, 26);
                    cout << "You are out of stamina. Press R to rest.";
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
                break;
            case 'd':
                if (!stamina.check())
                {
                    cursorSet(0, 26);
                    cout << "You are out of stamina. Press R to rest.";
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
                break;
            case 'w':
                if (!stamina.check())
                {
                    cursorSet(0, 26);
                    cout << "You are out of stamina. Press R to rest.";
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
                break;
            case 's':
                if (!stamina.check())
                {
                    cursorSet(0, 26);
                    cout << "You are out of stamina. Press R to rest.";
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
                break;
            case 'r':
                cursorSet(0, 26);
                cout << setw(50) <<  " ";
                Sleep(450);
                stamina.increase();
                break;
            case 'p':
                for (int i = 0; i < 3; ++i)
                {
                    biomeRestrict[i] = 1;
                }
                break;
            default:
                cursorSet(0, 25);
                cout << "Invalid Key";
                Sleep(500);
                cursorSet(0, 25);
                cout << setw(50) << " ";
                break;

        }

    return;
}
