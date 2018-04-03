#ifndef WEAPON_CLASS_H_INCLUDED
#define WEAPON_CLASS_H_INCLUDED
#include "Status_Namespace.h"
class Weapon
{
private:
    bool sword;
    bool axe;
    int dmg;
    char type;
public:
    Weapon()
    {
        sword = true;
        axe = true;
        dmg = 1;
        type = 'N';//for nothing
    }
    Weapon(bool , bool, int, char);
    int set_damage_Output(Weapon &, char);
    bool getSword();
    bool getAxe();
    int getDmg();
    void setDmg(int);
};

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
