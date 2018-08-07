#include "entityCheck.h"
#include "../Biome_Class/Biome_Class.h"
#include "../getTreasure/getTreasure.h"
#include "../village/village.h"
#include "../cave/cave.h"
#include "../Player_Combat_Weapon/include/Player_Class.h"
#include "../Player_Combat_Weapon/include/Combat_Event_Prototype.h"
#include "../displayMap/displayMap.h"
void entityCheck(Biome& biome, int x, int y)
{
    Player_Class player("Josh", 2,3,10,0,10,2);
    Weapon_Class weapon(2,'F', "Josh's Sword");
    Armor_Class armor(2,"Josh's Armor", "I");
    Moves_Class move("Josh Move",3, 10, "F");
    player.moveList.push_back(move);
    player.weaponInventory.push_back(weapon);
    player.armorInventory.push_back(armor);
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
            displayMap(biome.map, biome.getColor());
            //monster stuff
            break;
        case 'V':
            village();
    }

}

