#include "Food.h"
#include "../player/player.h"
#include <cstdlib>

Food::Food()
{
    if (rand() % 10 > 5)
    {
        recover = (player::players.getHealth() * 2) / 10;
        foodName = "bread";
    }
    else if (rand() % 10 > 6)
    {
        recover = (player::players.getHealth() * 3) / 10;
        foodName = "eggs";
    }
    else if (rand() % 10 > 7)
    {
        recover = (player::players.getHealth() * 4) / 10;
        foodName = "chicken";
    }
    else if (rand() % 10 > 8)
    {
        recover = (player::players.getHealth() * 6) / 10;
        foodName = "steak";
    }
    else if (rand() % 10 > 8)
    {
        recover = (player::players.getHealth() * 8) / 10;
        foodName = "ribs";
    }
    else
    {
        recover = (player::players.getHealth() * 1) / 10;
        foodName = "grapes";
    }
}

string Food::getFoodName()
{
    return foodName;
}

