#ifndef BIOME_CONSTRUCTORS
#define BIOME_CONSTRUCTORS

Biome::Biome() : heat(0), biome('F')
{
    char fog;
    switch(biome)
    {
        case 'F':
            fog = '#';
            break;
        case 'T':
            fog = '*';
            break;
        case 'D':
            fog = '~';
            break;
        case 'M':
            fog = '+';
            break;
    }
    for (int i = 0; i < MAPSIZEY; ++i)
    {
        for (int j = 0; j < MAPSIZEX; ++j)
        {
            map[i][j] = fog;
            entityMap[i][j] = '\'';
        }
    }
    entityMapPop();
}

Biome::Biome(int temp, char type) : heat(temp), biome(type)
{
    char fog;
    switch(biome)
    {
        case 'F':
            fog = '#';
            break;
        case 'T':
            fog = '*';
            break;
        case 'D':
            fog = '~';
            break;
        case 'M':
            fog = '+';
            break;
    }
    for (int i = 0; i < MAPSIZEY; ++i)
    {
        for (int j = 0; j < MAPSIZEX; ++j)
        {
            map[i][j] = fog;
            entityMap[i][j] = '\'';
        }
    }
    entityMapPop();
}

void Biome::entityMapPop()
{
    srand(time(0));
    char types[] = {'C', 'T', 'V', 'M', '\''};
    int num = 0;
    for (int i = 0; i < MAPSIZEY; ++i)
    {
        for (int j = 0; j < MAPSIZEX; ++j)
        {
            if ((rand() % 10) == 0)
                num = (rand() % 4);
            else
                num = 4;
            entityMap[i][j] = types[num];
        }
    }
}

char Biome::getEntity(int y, int x)
{
    char entity;
    entity = entityMap[y][x];
    if (entity == 'M')
        entity = '\'';
    return entity;
}

#endif // BIOME_CONSTRUCTORS
