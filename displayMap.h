#ifndef DISPLAYMAP
#define DISPLAYMAP

void displayMap(char map[][MAPSIZEX])
{
    cout << string(100, '\n');
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
