#include <iostream>
#include <string>
#include "../include/Armor_Class.h"

Armor_Class::Armor_Class()
{
    //ctor
    armor = 0;
    name = " ";
    type = "0";

}

Armor_Class::Armor_Class(int arm, std::string nameof, std::string resist)
{
    armor = arm;
    name = nameof;
    type = resist;
}

int Armor_Class::getArmor()
{
    return armor;
}

void Armor_Class::setArmor(int arm)
{
    armor = arm;
}

std::string Armor_Class::getType()
{
    return type;
}
std::string Armor_Class::getName()
{
    return name;
}
