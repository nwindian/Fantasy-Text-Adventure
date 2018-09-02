#include "setGate.h"
#include "../Biome_Class/Biome_Class.h"
// 0 Forest middle - 1 Tundra bottom - 2 Desert right - 3 Mountain left
// Tundra Gate y = 0, Desert Gate x = 0, Mountain Gate x = 49
// forest Gates: Tundra y = 24, Desert x = 49, Mountain x = 0
// y then x

void setGate(Biome maps[])
{
    //Forest Gates
    {
        //Tundra
        maps[0].entityMap[24][maps[1].biomeGate].type = 'G';
        //Desert
        maps[0].entityMap[maps[2].biomeGate][49].type = 'G';
        //Mountain
        maps[0].entityMap[maps[3].biomeGate][0].type = 'G';
    }
    //Tundra
    maps[1].entityMap[0][maps[1].biomeGate].type = 'G';
    //Desert
    maps[2].entityMap[maps[2].biomeGate][0].type = 'G';
    //Mountain
    maps[3].entityMap[maps[3].biomeGate][49].type = 'G';
    for (int k = 0; k < 4; ++k)
    {
        for (int i = 0; i < MAPSIZEY; ++i)
        {
            for (int j = 0; j < MAPSIZEX; ++j)
            {
                maps[k].map[i][j] = maps[k].entityMap[i][j].type;
            }
        }
    }
}
