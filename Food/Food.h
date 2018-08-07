#ifndef FOOD_H
#define FOOD_H
#include <string>
using std::string;
class Food
{
    public:
        Food();
        string getFoodName();
        string foodName = " ";
    private:
        int recover = 0;

};

#endif // FOOD_H
