#ifndef WEAPON_CLASS_INTERFACE_H_INCLUDED
#define WEAPON_CLASS_INTERFACE_H_INCLUDED
#include <iostream>
#include <string>

class Weapon
{
private:
    bool sword;
    bool axe;
    int dmg;
    char type;
    std::string name;
public:
    Weapon()
    {
        name = " ";
        sword = true;
        axe = true;
        dmg = 1;
        type = 'N';//for nothing
    }
    Weapon(bool s , bool a, int d, char t, std::string n)
    {
        sword = s;
        axe = a;
        dmg = d;
        type = t;
        name = n;
    }
    int set_damage_Output(Weapon &, char);
    bool getSword();
    bool getAxe();
    int getDmg();
    std::string getName();
    void setDmg(int);
};


#endif // WEAPON_CLASS_INTERFACE_H_INCLUDED
