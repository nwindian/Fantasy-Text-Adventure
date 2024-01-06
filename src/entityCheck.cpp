#include "entityCheck.h"
#include "../include/Biome_Class.h"
#include "../include/getTreasure.h"
#include "../include/village.h"
#include "../include/cave.h"
#include "../Player_Combat_Weapon/include/Player_Class.h"
#include "../Player_Combat_Weapon/include/Combat_Event_Prototype.h"
#include "../include/displayMap.h"
#include "../include/player.h"
void entityCheck(Biome& biome, int x, int y)
{
    switch (biome.getEntity(y, x))
    {
        case 'C':
            cave(biome, y, x);
            break;
        case 'T':
            getTreasure();
            break;
        case 'M':
            combat(player::players, biome.getBiome());
            displayMap(biome.map, biome.getColor());
            break;
        case 'V':
            village();
            break;
    }
    return;
}

