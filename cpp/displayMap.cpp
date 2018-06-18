void displayMap(char map[][MAPSIZEX], int color)
{
    CursorPosition.X = 0;
    CursorPosition.Y = 0;
    SetConsoleCursorPosition(console,CursorPosition);
    switch(color)
    {
        case 2:
            rlutil::setConsoleTitle("Forest");
            break;
        case 11:
            rlutil::setConsoleTitle("Tundra");
            break;
        case 14:
            rlutil::setConsoleTitle("Desert");
            break;
        case 8:
            rlutil::setConsoleTitle("Mountain");
            break;
    }
    for (int i = 0; i < MAPSIZEY ; ++i)
    {
        for (int j = 0;  j < MAPSIZEX; ++j)
        {
            if (map[i][j] == '\'')
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    return;
}
