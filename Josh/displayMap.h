#ifndef DISPLAYMAP
#define DISPLAYMAP



void displayMap(char map[][MAPSIZEX])
{
    CursorPosition.X = 0;
    CursorPosition.Y = 0;
    SetConsoleCursorPosition(console,CursorPosition);
    //system ("CLS");
    for (int i = 0; i < MAPSIZEY ; ++i)
    {
        for (int j = 0;  j < MAPSIZEX; ++j)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

#endif // DISPLAYMAP
