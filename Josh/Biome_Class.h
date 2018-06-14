#ifndef BIOME_CLASS
#define BIOME_CLASS

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
        //char map[MAPSIZEY][MAPSIZEX];
        char* map;
        //Entities entityMap[MAPSIZEY][MAPSIZEX];
        Entities* entityMap;
        vector<Cave> caves;
        char getEntity(int, int);
        void entityMapPop(int);
        int getColor() { return color; }


};

#endif // BIOME_CLASS
