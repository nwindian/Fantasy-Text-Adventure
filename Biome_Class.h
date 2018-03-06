#ifndef BIOME_CLASS
#define BIOME_CLASS

class Biome
{
    private:
        int heat;
        char biome;
    public:
        Biome();
        Biome(int, char);
        char map[MAPSIZEY][MAPSIZEX];
        char entityMap[MAPSIZEY][MAPSIZEX];
        char getEntity(int, int);
        void entityMapPop();

};

#endif // BIOME_CLASS
