#ifndef BIOME_CLASS
#define BIOME_CLASS
#include "../mapSizes/mapSizes.h"
#include "../cave_Class/cave_class.h"
#include <vector>
class Biome
{
    private:
        int heat;
        char biome;
        int color = 0;
        struct Entities
        {
            char type = '\'';
            int caveNumber = 0;
            Entities() : type('\'') , caveNumber(0)
            {
            }
            Entities(char i, int j) : type(i) , caveNumber (j)
            {
            }
        };

    public:
        Biome();
        Biome(int, char, int);
        char** map;
        Entities** entityMap;
        std::vector<Cave> caves;
        int biomeGate = 0;
        char getEntity(int, int);
        void entityMapPop(int);
        char getBiome() { return biome; }
        int getColor() { return color; }
};

#endif // BIOME_CLASS
