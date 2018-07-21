#ifndef BIOME_CLASS
#define BIOME_CLASS
#include "../Josh/mapSizes.h"
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
            int number = 0;
            Entities() : type('\''), number(0)
            {
            }
            Entities(char i, int j) : type(i), number(j)
            {
            }
        };

    public:
        static int caveCount;
        Biome();
        Biome(int, char, int);
        char** map;
        Entities** entityMap;
        std::vector<Cave> caves;
        char getEntity(int, int);
        void entityMapPop(int);
        int getColor() { return color; }
};

#endif // BIOME_CLASS
