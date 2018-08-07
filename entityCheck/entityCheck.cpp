#include "entityCheck.h"
#include "../Biome_Class/Biome_Class.h"
#include "../getTreasure/getTreasure.h"
#include "../village/village.h"
#include "../cave/cave.h"
#include "../Player_Combat_Weapon/include/Player_Class.h"
#include "../Player_Combat_Weapon/include/Combat_Event_Prototype.h"
void entityCheck(Biome& biome, int x, int y)
{
    Player_Class player;
    switch (biome.getEntity(y, x))
    {
        case 'C':
            cave(biome, y, x);
            break;
        case 'T':
            getTreasure();
            break;
        case 'M':
            combat(player, biome.getBiome());
            //monster stuff
            break;
        case 'V':
            village();
    }

}

