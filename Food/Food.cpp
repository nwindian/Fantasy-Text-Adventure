#include "Food.h"
#include <cstdlib>

Food::Food()
{
    if (rand() % 10 > 5)
    {
        //recover = (Joe.getHealth() * 25) / 100;
        foodName = "is bread";
    }
    else if (rand() % 10 > 6)
    {
        //recover = (Joe.getHealth() * 30) / 100;
        foodName = "are eggs";
    }
    else if (rand() % 10 > 7)
    {
        //recover = (Joe.getHealth() * 40) / 100;
        foodName = "is cooked chicken";
    }
    else if (rand() % 10 > 8)
    {
        //recover = (Joe.getHealth() * 50) / 100;
        foodName = "is cooked steak";
    }
    else if (rand() % 10 > 8)
    {
        //recover = (Joe.getHealth() * 75) / 100;
        foodName = "are cooked ribs";
    }
    else
    {
        //recover = (Joe.getHealth() * 20) / 100;
        foodName = "are grapes";
    }
}

string Food::getFoodName()
{
    return foodName;
}

