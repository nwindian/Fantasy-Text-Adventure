char entityCheck()
{
    switch (maps[biome].getEntity(y, x))
    {
        case 'C':
            cave(maps[biome], y, x);
            break;
        case 'T':
            getTreasure();
            break;
        case 'M':
            //monster stuff
            break;
        case 'V':
            village();
    }
}

