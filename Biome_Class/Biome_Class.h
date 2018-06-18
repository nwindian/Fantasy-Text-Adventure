#ifndef BIOME_CLASS
#define BIOME_CLASS
#include "../Josh/mapSizes.h"
#include "../cave_Class/cave_class.h"
#include <memory>
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
        std::unique_ptr<char[][MAPSIZEX]> map = std::make_unique<char[][MAPSIZEX]>(MAPSIZEY, MAPSIZEX);
        //char map[MAPSIZEY][MAPSIZEX];
        std::unique_ptr<Entities[][MAPSIZEX]> entityMap = std::make_unique<Entities[][MAPSIZEX]>(MAPSIZEY, MAPSIZEX);
        //Entities entityMap[MAPSIZEY][MAPSIZEX];
        std::vector<Cave> caves;
        char getEntity(int, int);
        void entityMapPop(int);
        int getColor() { return color; }
};

#endif // BIOME_CLASS
