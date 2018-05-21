#include <iostream>
#include <string>
#include "Weapon_Class.h"

Weapon_Class::Weapon_Class()
{
    name = " ";
    dmg = 1;
    type = 'N';//for nothing
}

Weapon_Class::Weapon_Class(int d, char t, std::string n)
{
    dmg = d;
    type = t;
    name = n;
}

Weapon_Class::Weapon_Class(const Weapon_Class& obj)
{
    dmg = obj.getDmg();
    type = obj.getType();
    name = obj.getName();
}

std::string Weapon_Class::getName() const
{
    return name;
}
//Getter method to get damage int value from class Weapon
int Weapon_Class::getDmg() const
{
    return dmg;
}
//Setter method to set damage int value from class Weapon
void Weapon_Class::setDmg(int oldDmg)
{
    dmg = oldDmg;
}
//Getter method to get sword bool value from class Weapon
bool Weapon_Class::getSword() const
{
    //return sword;
}
//Getter method to get axe bool value from class Weapon
bool Weapon_Class::getAxe() const
{
    //return axe;
}
//getter for type
char Weapon_Class::getType() const
{
    return type;
}
//int Weapon_Class::setDmg(Weapon & weapon, char typeWpn)//MAY NEED TO INCLUDE MONSTER OBJECT TO CHECK RESISTANCES
//{
//    int damage = weapon.getDmg();
//    if (typeWpn == 'p')
//    {
//        //run future damage resistance function
//        damage = damage + status::poison; //Later make each status damage a global constant
//        return damage;
//    }
//    else if(typeWpn == 'b')
//    {
//        //run future damage resistance function
//        damage = damage + status::burn;
//        return damage;
//    }
//    else if(typeWpn == 'r')
//    {
//        //run future damage resistance function
//        damage = damage + status::bleed;
//        return damage;
//    }
//}
