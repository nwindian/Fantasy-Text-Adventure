#include <iostream>
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

void village()
{
    cursorSet(0, 26)
    cout << "Would you like to enter the village? (Y)es (N)o";
    do
    {
        char responce = getch();
        if (responce == 'y')
        {
            MoveWindow(console, r.left, r.top, 773, 520, TRUE);
            cursorSet(0, 26)
            cout << setw(30) << "Where would you like to go?\n";
            cout << "(1) Weapon and Armor Smith\n"
                 << "(2) Food Shop\n"
                 << "(3) Scroll shop\n"
                 << "(4) Explore";

        }
        else if (responce == 'n')
        {
            cursorSet(0, 26)
            cout << setw(30) << "Very well";
        }
}

void getTreasure()
{
    string loot;
    int goldCount = 0;
    int num = rand() % 1121;
    if (num > 599)
    {
        if (num < 840)
        {
            food = true;
            foodObj = std::unique_ptr<Food>(new Food());
            loot = foodObj->foodName;
        }
        else if (num < 960)
        {
            gold = true;
            goldNum = (rand() % 20 + 30);
            loot = "is gold";
        }
        else if (num < 1000)
        {
            weapon = true;
            loot = "is a weapon";
        }
        else if (num < 1080)
        {
            scroll = true;
            loot = "is a scroll";
        }
        else if (num == 1120)
        {
            //caveIn
        }
        else
        {
            armor = true;
            loot = "is armor";
        }
    }
    else
    {
        loot = "nothing";
    }
}
