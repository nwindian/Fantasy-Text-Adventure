#ifndef BIOME_CONSTRUCTORS
#define BIOME_CONSTRUCTORS

Biome::Biome() : heat(0), biome('F')
{

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

Biome::Biome(int temp, char type) : heat(temp), biome(type)
{

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
    char types[] = {'C', 'T', 'V', 'M', '\''};
    int typeCount[] = {0, 0, 0, 0,};
    int num = 0;
    for (int i = 0; i < Size; ++i)
    {
        int y = rand() % 25;
        int x = rand() % 50;
        entityMap[y][x].type = '\'';

    }
    for (int i = 0; i < MAPSIZEY; ++i)
    {
        for (int j = 0; j < MAPSIZEX; ++j)
        {
            if ((rand() % 10) == 0)
                num = (rand() % 4);
            else
                num = 4;
            entityMap[i][j].type = types[num];
            entityMap[i][j].number = typeCount[num];
            ++typeCount[num];
        }
    }
}

int Biome::accessStatic()
{

}
char Biome::getEntity(int y, int x)
{
    char entity;
    entity = entityMap[y][x].type;
    if (entity == 'M')
        entity = '\'';
    return entity;
}



#endif // BIOME_CONSTRUCTORS
