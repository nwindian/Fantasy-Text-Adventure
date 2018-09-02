#include "addMonster.h"
#include "../Biome_Class/Biome_Class.h"

void addMonster(Biome& biome)
{
    do
    {
        int y = rand() % 23 + 1;
        int x = rand() % 48 + 1;
        if (biome.entityMap[y][x].type == '\'')
        {
                if (biome.entityMap[y+1][x].type != 'M' ||
                    biome.entityMap[y-1][x].type != 'M' ||
                    biome.entityMap[y][x+1].type != 'M' ||
                    biome.entityMap[y][x-1].type != 'M')
                {
                    biome.entityMap[y][x].type = 'M';
                    if (biome.map[y][x] == '\'')
                    {
                        biome.map[y][x] = 'M';
                    }
                    return;
                }
        }

    } while(true);
}
