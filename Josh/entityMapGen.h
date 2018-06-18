#ifndef ENTITYMAPGEN
#define ENTITYMAPGEN
#include "mapSizes.h"
void entityMapGen(char map[][MAPSIZEY][MAPSIZEX])
{
    for (int i = 0; i < MAPSIZEY; ++i)
    {
        for (int j = 0; j < MAPSIZEX; ++j)
        {
            map[i][j] = '\'';
        }
    }
}
#endif // ENTITYMAPGEN
