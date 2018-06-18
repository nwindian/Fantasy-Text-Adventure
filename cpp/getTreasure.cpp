void getTreasure()
{
    string loot;
    int goldCount = 0;
    int num = rand() % 1121;
    if (num > 599)
    {
        if (num < 840)
        {
            //foodObj = std::unique_ptr<Food>(new Food());
            //loot = foodObj->foodName;
        }
        else if (num < 960)
        {

            //goldNum = (rand() % 20 + 30);
            loot = "is gold";
        }
        else if (num < 1000)
        {

            loot = "is a weapon";
        }
        else if (num < 1080)
        {

            loot = "is a scroll";
        }
        else if (num == 1120)
        {
            //caveIn
        }
        else
        {

            loot = "is armor";
        }
    }
    else
    {
        loot = "nothing";
    }
}
