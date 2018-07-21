#include <iostream>
#include <string>
#include "Moves_Class.h"


Moves_Class::Moves_Class()
{
    //ctor
    damage = 0;
    name = " ";
    evasiveness = 100;
}

Moves_Class::Moves_Class(std::string nameO, int damageO, int evasivenesss, std::string typo)
{
    damage = damageO;
    name = nameO;
    evasiveness = evasivenesss;
    type = typo;
}

int Moves_Class::getDamage()
{
    return damage;
}

int Moves_Class::getEvasive()
{
    return evasiveness;
}

std::string Moves_Class::getName()
{
    return name;
}

std::string Moves_Class::getType()
{
    return type;
}
