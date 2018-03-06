#ifndef PLAYERVIEW
#define PLAYERVIEW

void playerView(Biome& biome, int x, int y)
{
    biome.map[y][x] = '@';
    if ((x-1) >= 0)
        biome.map[y][x-1] = biome.getEntity(y, x-1);
    if ((x+1) < MAPSIZEX)
        biome.map[y][x+1] = biome.getEntity(y, x+1);
    if ((y-1) >= 0)
        biome.map[y-1][x] = biome.getEntity(y-1, x);
    if ((y+1) < MAPSIZEY)
        biome.map[y+1][x] = biome.getEntity(y+1, x);
    return;
}


#endif // PLAYERVIEW
