void moveOptions(int x, int y, int biome, int allowed[])
{
   // cout << endl << "Use the arrow keys to move. \nYou may move,";
    if ((x-1) >= 0 || biome == 0 || biome == 2)
    {
        allowed[0] = 1;
    }
    if ((x+1) < MAPSIZEX || biome == 0 || biome == 3)
    {
        allowed[1] = 1;
    }
    if ((y-1) >= 0 || biome == 1)
    {
        allowed[2] = 1;
    }
    if ((y+1) < MAPSIZEY || biome == 0)
    {
        allowed[3] = 1;
    }
    return;
}
