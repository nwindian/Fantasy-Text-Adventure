#ifndef DAMAGE_CALCULATOR_HPP_INCLUDED
#define DAMAGE_CALCULATOR_HPP_INCLUDED
#include <iostream>
#include "Weapon_Class.h"

int dmg_calc(Player &, Player &, Weapon &);

int dmg_calc(Player & player, Player & enemy, Weapon & weapon)
{
    int damage = player.setDamage();
    int wdamage = weapon.getDmg();
    char type = weapon.getType();
    //add resistance and type to total damage;
    //ADD MOVE TO PARMS AND IMPLICATE IT
    return return (damage + wdamage + (damage / 2)) * 2;

}


#endif // DAMAGE_CALCULATOR_HPP_INCLUDED
