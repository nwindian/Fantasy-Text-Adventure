#include "playerView.h"
#include "../cursorSet/cursorSet.h"
#include "../Stamina/Stamina.h"
#include "../Biome_Class/Biome_Class.h"
#include <iostream>
#include <windows.h>
using std::cout;
void playerView(Biome& biome, int x, int y, Stamina& stamina)
{
    cursorSet(0, 27);
    stamina.display();
    cursorSet(0, 0);
    biome.map[y][x] = '@';
    cursorSet(2*x, y);
    cout << biome.map[y][x];
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), biome.getColor());
    if ((x-1) >= 0)
    {
        biome.map[y][x-1] = biome.getEntity(y, x-1);
        cursorSet((2*x)-2, y);
        cout << biome.map[y][x-1];
    }
    if ((x+1) < MAPSIZEX)
    {
        biome.map[y][x+1] = biome.getEntity(y, x+1);
        cursorSet((2*x)+2, y);
        cout << biome.map[y][x+1];
    }
    if ((y-1) >= 0)
    {
        biome.map[y-1][x] = biome.getEntity(y-1, x);
        cursorSet(2*x, y-1);
        cout << biome.map[y-1][x];
    }
    if ((y+1) < MAPSIZEY)
    {
        biome.map[y+1][x] = biome.getEntity(y+1, x);
        cursorSet(2*x, y+1);
        cout << biome.map[y+1][x];
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    return;
}
