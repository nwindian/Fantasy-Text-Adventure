#include "../include/playerView.h"
#include "../include/cursorSet.h"
#include "../include/Stamina.h"
#include "../include/Biome_Class.h"
#include "../include/charOutput.h"
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
    int color = biome.getColor();
    if ((x-1) >= 0)
    {
        biome.map[y][x-1] = biome.getEntity(y, x-1);
        cursorSet((2*x)-2, y);
        charOutput(biome.map[y][x-1], color);
    }
    if ((x+1) < MAPSIZEX)
    {
        biome.map[y][x+1] = biome.getEntity(y, x+1);
        cursorSet((2*x)+2, y);
        charOutput(biome.map[y][x+1], color);
    }
    if ((y-1) >= 0)
    {
        biome.map[y-1][x] = biome.getEntity(y-1, x);
        cursorSet(2*x, y-1);
        charOutput(biome.map[y-1][x], color);
    }
    if ((y+1) < MAPSIZEY)
    {
        biome.map[y+1][x] = biome.getEntity(y+1, x);
        cursorSet(2*x, y+1);
        charOutput(biome.map[y+1][x], color);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    return;
}
