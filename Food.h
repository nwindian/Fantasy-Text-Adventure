#ifndef FOOD_H
#define FOOD_H

class Food
{
    public:
        Food();
        string getFoodName();
    private:
        int recover = 0;
        string foodName;
};

#endif // FOOD_H
