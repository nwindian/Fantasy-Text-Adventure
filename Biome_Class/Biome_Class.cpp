#include "Biome_Class.h"
#include "../mapSizes/mapSizes.h"
#include "../cave_Class/cave_class.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Biome::Biome() : heat(0), biome('F'), color(2)
{

    map = new char*[MAPSIZEY];
    entityMap = new Entities*[MAPSIZEY];
    for (int i = 0; i < MAPSIZEY; ++i)
    {
        map[i] = new char[MAPSIZEX];
        entityMap[i] = new Entities[MAPSIZEX];
    }
    char fog;
    int Size = 0;
    switch(biome)
    {
        case 'F':
            fog = '#';
            Size = 15;
            break;
        case 'T':
            fog = '*';
            Size = 15;
            break;
        case 'D':
            fog = '~';
            Size = 0;
            break;
        case 'M':
            fog = '+';
            Size = 30;
            break;
    }
    for (int i = 0; i < Size; ++i)
    {
        caves.push_back(Cave());
    }
    for (int i = 0; i < MAPSIZEY; ++i)
    {
        for (int j = 0; j < MAPSIZEX; ++j)
        {
            map[i][j] = fog;
            entityMap[i][j] = Entities();
        }
    }
    entityMapPop(Size);
}

Biome::Biome(int temp, char type, int c) : heat(temp), biome(type), color(c)
{
    map = new char*[MAPSIZEY];
    entityMap = new Entities*[MAPSIZEY];
    for (int i = 0; i < MAPSIZEY; ++i)
    {
        map[i] = new char[MAPSIZEX];
        entityMap[i] = new Entities[MAPSIZEX];
    }
    char fog;
    int Size = 0;
    switch(biome)
    {
        case 'F':
            fog = '#';
            Size = 15;
            break;
        case 'T':
            fog = '*';
            Size = 15;
            break;
        case 'D':
            fog = '~';
            Size = 0;
            break;
        case 'M':
            fog = '+';
            Size = 30;
            break;
    }
    for (int i = 0; i < Size; ++i)
    {
        caves.push_back(Cave());
    }
    for (int i = 0; i < MAPSIZEY; ++i)
    {
        for (int j = 0; j < MAPSIZEX; ++j)
        {
            map[i][j] = fog;
            entityMap[i][j] = Entities();
        }
    }
    entityMapPop(Size);
}

void Biome::entityMapPop(int Size)
{
    srand(time(0));
    entityMap[13][23].type = '|';
    entityMap[13][25].type = '|';
    entityMap[14][23].type = '|';
    entityMap[14][25].type = '|';
    entityMap[12][24].type = '_';
    entityMap[14][24].type = '_';
    entityMap[13][24].type = 'I';
    char types[] = {'C', 'T', 'V', 'M', '\''};
    int total = 4, counts[] = {Size, (rand() % 10 + 20), 3, 50};
    for (int i = 0; i < total; ++i)
    {
        for (int j = 0; j < counts[i];)
        {
            int num = 0;
            int y = rand() % 23 + 1;
            int x = rand() % 48 + 1;
            if (entityMap[y][x].type == '\'')
            {
                    num = i;
                    if (entityMap[y+1][x].type != '\'' ||
                        entityMap[y-1][x].type != '\'' ||
                        entityMap[y][x+1].type != '\'' ||
                        entityMap[y][x-1].type != '\'')
                    {
                        num = 4;
                    }
                    else
                    {
                        ++j;
                    }
                entityMap[y][x].type = types[num];
            }

        }
    }
}

char Biome::getEntity(int y, int x)
{
    char entity;
    entity = entityMap[y][x].type;
    return entity;
}
