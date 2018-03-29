#ifndef PLAYERVIEW
#define PLAYERVIEW



void playerView(Biome& biome, int x, int y)
{
    CursorPosition.X = 0;
    CursorPosition.Y = 0;
    SetConsoleCursorPosition(console,CursorPosition);
    biome.map[y][x] = '@';
    CursorPosition.X = (2*x);
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console,CursorPosition);
    cout << biome.map[y][x];
    if ((x-1) >= 0)
    {
        biome.map[y][x-1] = biome.getEntity(y, x-1);
        CursorPosition.X = (2*x)-2;
        CursorPosition.Y = y;
        SetConsoleCursorPosition(console,CursorPosition);
        cout << biome.map[y][x-1];
    }
    if ((x+1) < MAPSIZEX)
    {
        biome.map[y][x+1] = biome.getEntity(y, x+1);
        CursorPosition.X = (2*x)+2;
        CursorPosition.Y = y;
        SetConsoleCursorPosition(console,CursorPosition);
        cout << biome.map[y][x+1];
    }
    if ((y-1) >= 0)
    {
        biome.map[y-1][x] = biome.getEntity(y-1, x);
        CursorPosition.X = (2*x);
        CursorPosition.Y = y-1;
        SetConsoleCursorPosition(console,CursorPosition);
        cout << biome.map[y-1][x];
    }
    if ((y+1) < MAPSIZEY)
    {
        biome.map[y+1][x] = biome.getEntity(y+1, x);
        CursorPosition.X = (2*x);
        CursorPosition.Y = y+1;
        SetConsoleCursorPosition(console,CursorPosition);
        cout << biome.map[y+1][x];
    }
    return;
}


#endif // PLAYERVIEW
