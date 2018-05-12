#ifndef WEAPON_CLASS_H_INCLUDED
#define WEAPON_CLASS_H_INCLUDED
#include "Status_Namespace.h"
#include <iostream>
#include <string>
#include "Weapon_Class_Interface.h"
//To get name of weapon
std::string Weapon::getName()
{
    return name;
}

//Getter method to get damage int value from class Weapon
int Weapon::getDmg()
{
    return dmg;
}
//Setter method to set damage int value from class Weapon
void Weapon::setDmg(int oldDmg)
{
    dmg = oldDmg;
}
//Getter method to get sword bool value from class Weapon
bool Weapon::getSword()
{
    return sword;
}
//Getter method to get axe bool value from class Weapon
bool Weapon::getAxe()
{
    return axe;
}
int Weapon::set_damage_Output(Weapon & weapon, char typeWpn)//MAY NEED TO INCLUDE MONSTER OBJECT TO CHECK RESISTANCES
{
    int damage = weapon.getDmg();
    if (typeWpn == 'p')
    {
        //run future damage resistance function
        damage = damage + status::poison; //Later make each status damage a global constant
        return damage;
    }
    else if(typeWpn == 'b')
    {
        //run future damage resistance function
        damage = damage + status::burn;
        return damage;
    }
    else if(typeWpn == 'r')
    {
        //run future damage resistance function
        damage = damage + status::bleed;
        return damage;
    }
}
#endif // WEAPON_CLASS_H_INCLUDED
