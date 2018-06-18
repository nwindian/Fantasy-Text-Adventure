#include "Food_Class.h"

Food_Class::Food_Class()
{
    amount = 0;
    name = "food";
}

Food_Class::Food_Class(int amt, std::string nme)
{
    amount = amt;
    name = nme;
}

Food_Class::~Food_Class()
{
    //dtor
}

std::string Food_Class::getName()
{
    return name;
}

int Food_Class::getAmount()
{
   return amount;
}

void Food_Class::setAmount(int amt)
{
    amount = amt;
}

void Food_Class::setName(std::string namee)
{
    name = namee;
}
