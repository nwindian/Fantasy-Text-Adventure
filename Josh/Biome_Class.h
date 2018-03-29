#ifndef BIOME_CLASS
#define BIOME_CLASS




class Biome
{
    private:
        int heat;
        char biome;
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
        Biome(int, char);
        char map[MAPSIZEY][MAPSIZEX];
        Entities entityMap[MAPSIZEY][MAPSIZEX];
        int accessStatic();
        vector<Cave> caves;
        char getEntity(int, int);
        void entityMapPop(int);


};

#endif // BIOME_CLASS
