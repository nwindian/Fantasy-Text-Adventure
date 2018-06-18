#include "entityCheck.h"
#include "../Biome_Class/Biome_Class.h"
#include "../getTreasure/getTreasure.h"
#include "../village/village.h"
#include "../cave/cave.h"
char entityCheck(Biome& biome, int x, int y)
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
            //monster stuff
            break;
        case 'V':
            village();
    }
}

