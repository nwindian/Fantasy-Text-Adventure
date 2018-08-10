#include "entityCheck.h"
#include "../Biome_Class/Biome_Class.h"
#include "../getTreasure/getTreasure.h"
#include "../village/village.h"
#include "../cave/cave.h"
#include "../Player_Combat_Weapon/include/Player_Class.h"
#include "../Player_Combat_Weapon/include/Combat_Event_Prototype.h"
#include "../displayMap/displayMap.h"
#include "../player/player.h"
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

