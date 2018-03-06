#ifndef MOVING
#define MOVING

void moving(int& x, int& y, int biome)
{
    char direction = ' ';
    int allowed[4] = {0};
    moveOptions(x, y, biome, allowed);
    cin >> direction;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    switch (direction)
    {
        case 'L':
            if (allowed[0] == 1)
                --x;
            else
            {
                cout << "You can't go here...";
                cin.get();
            }
            break;
        case 'l':
            if (allowed[0] == 1)
                --x;
            else
            {
                cout << "You can't go here...";
                cin.get();
            }
            break;
        case 'R':
            if (allowed[1] == 1)
                ++x;
            else
            {
                cout << "You can't go here...";
                cin.get();
            }
            break;
        case 'r':
            if (allowed[1] == 1)
                ++x;
            else
            {
                cout << "You can't go here...";
                cin.get();
            }
            break;
        case 'U':
            if (allowed[2] == 1)
                --y;
            else
            {
                cout << "You can't go here...";
                cin.get();
            }
            break;
        case 'u':
            if (allowed[2] == 1)
                --y;
            else
            {
                cout << "You can't go here...";
                cin.get();
            }
            break;
        case 'D':
            if (allowed[3] == 1)
                ++y;
            else
            {
                cout << "You can't go here...";
                cin.get();
            };
            break;
        case 'd':
            if (allowed[3] == 1)
                ++y;
            else
            {
                cout << "You can't go here...";
                cin.get();
            }
            break;
    }

    return;
}

#endif // MOVING
