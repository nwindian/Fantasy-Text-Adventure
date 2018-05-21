#include <iostream>
#include <string>
#include "Armor_Class.h"

Armor_Class::Armor_Class()
{
    //ctor
    armor = 0;
    name = " ";
    resistance = 'N';

}

Armor_Class::Armor_Class(int arm, std::string nameof, char resist)
{
    armor = arm;
    name = nameof;
    resistance = resist;
}
