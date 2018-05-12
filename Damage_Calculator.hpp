#ifndef DAMAGE_CALCULATOR_HPP_INCLUDED
#define DAMAGE_CALCULATOR_HPP_INCLUDED
#include <iostream>
#include "Weapon_Class.h"

int dmg_calc(Player &, Player &, Weapon &);

int dmg_calc(Player & player, Player & enemy, Weapon & weapon)
{
    int damage = player.setDamage();
    if (weapon)

}


#endif // DAMAGE_CALCULATOR_HPP_INCLUDED
