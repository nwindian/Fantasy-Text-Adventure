#ifndef FOOD_CLASS_H
#define FOOD_CLASS_H
#include <iostream>
#include "Loot_Class.h"


class Food_Class : public Loot_Class
{
    public:
        Food_Class();
        Food_Class(int, std::string);
        virtual ~Food_Class();
        std::string getName();
        int getAmount();
        void setName(std::string);
        void setAmount(int);

    protected:
        std::string name;
        int amount;
    private:
};

#endif // FOOD_CLASS_H
