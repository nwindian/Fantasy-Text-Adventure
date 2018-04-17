#ifndef CAVE_CLASS
#define CAVE_CLASS
struct food
{
    int recover = 0;
    string foodName;
    food()
    {
        if (rand() % 10 > 5)
        {
            recover = (player.getHealth() * 25)) / 100;
            foodName = "Bread";
        }
        else if (rand() % 10 > 6)
        {
            recover = (player.getHealth() * 30)) / 100;
            foodName = "Eggs";
        }
        else if (rand() % 10 > 7)
        {
            recover = (player.getHealth() * 40)) / 100;
            foodName = "Chicken";
        }
        else if (rand() % 10 > 8)
        {
            recover = (player.getHealth() * 50)) / 100;
            foodName = "Steak";
        }
        else if (rand() % 10 > 8)
        {
            recover = (player.getHealth() * 75)) / 100;
            foodName = "Ribs";
        }
        else
        {
            recover = (player.getHealth() * 20)) / 100;
            foodName = "Grapes";
        }
    }
};




class Cave
{
    private:
        int depth = 0;
        struct cavePiece
        {
            int heat = 0;
            string message;
            string loot;
            bool gold = false;
            int goldNum = 0;
            bool weapon = false;
            bool food = false;
            food* foodObj;
            //bool waterSkin = false;
            bool scroll = false;
            bool armor = false;
            cavePiece()
            {
                int num = rand() % 100;
                if (num < 50)
                {
                    if (num > 29)
                    {
                        food = true;
                        foodObj = new food();
                        loot = foodObj->foodName;
                    }
                    else if (num > 14)
                    {
                        gold = true;
                        goldNum = (rand() % 20 + 30);
                        loot = "gold";
                    }
                    else if (num > 9)
                    {
                        weapon = true;
                        loot = "a weapon";
                    }
                    else if (num > 4)
                    {
                        scroll = true;
                        loot = "a scroll";
                    }
                    else
                    {
                        armor = true;
                        loot = "armor";
                    }
                }
                else
                {
                    loot = "nothing";
                }
            }
            cavePiece(string& msg) : message(msg)
            {
                int num = rand() % 100;
                if (num < 50)
                {
                    if (num > 29)
                    {
                        food = true;
                        foodNum = (rand() % 20 + 10);
                        loot = "food";
                    }
                    else if (num > 14)
                    {
                        gold = true;
                        goldNum = (rand() % 20 + 30);
                        loot = "gold";
                    }
                    else if (num > 9)
                    {
                        weapon = true;
                        loot = "a weapon";
                    }
                    else if (num > 4)
                    {
                        scroll = true;
                        loot = "a scroll";
                    }
                    else
                    {
                        armor = true;
                        loot = "armor";
                    }
                }
                else
                {
                    loot = "nothing";
                }
            }
        };
        cavePiece* theCave;
    public:
        Cave();
        void display();
};

#endif // CAVE_CLASS
