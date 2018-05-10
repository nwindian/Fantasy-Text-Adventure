#ifndef CAVE_CLASS
#define CAVE_CLASS
using namespace playerSpace;
struct Food
{
    int recover = 0;
    string foodName;
    Food()
    {
        if (rand() % 10 > 5)
        {
            recover = (Joe.getHealth() * 25) / 100;
            foodName = "is bread";
        }
        else if (rand() % 10 > 6)
        {
            recover = (Joe.getHealth() * 30) / 100;
            foodName = "are eggs";
        }
        else if (rand() % 10 > 7)
        {
            recover = (Joe.getHealth() * 40) / 100;
            foodName = "is cooked chicken";
        }
        else if (rand() % 10 > 8)
        {
            recover = (Joe.getHealth() * 50) / 100;
            foodName = "is cooked steak";
        }
        else if (rand() % 10 > 8)
        {
            recover = (Joe.getHealth() * 75) / 100;
            foodName = "are cooked ribs";
        }
        else
        {
            recover = (Joe.getHealth() * 20) / 100;
            foodName = "are grapes";
        }
    }
};


class Monster
{

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
            std::unique_ptr<Food> foodObj;
            Monster* entity;
            //bool waterSkin = false;
            bool scroll = false;
            bool armor = false;
            cavePiece()
            {
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
            cavePiece(string& msg) : message(msg)
            {
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
            cavePiece(Monster& ent) : entity(&ent)
            {
            }
        };
        cavePiece* theCave;
    public:
        Cave();
        void display();
};

#endif // CAVE_CLASS
