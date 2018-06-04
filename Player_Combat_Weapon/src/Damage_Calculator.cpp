#include <iostream>
#include "Monster.hpp"
#include "Player_Class.h"
#include "Weapon_Class.h"
#include "Damage_Calculator.h"
#include "Moves_Class.h"



int dmg_calc(Player_Class & player, Monster & enemy, Weapon_Class & weapon, Moves_Class & move)
{
    int movdamage = move.getDamage();
    int damage = player.getStrength();
    int wdamage = weapon.getDmg();
    char type = weapon.getType();
    //add resistance and type to total damage;
    //ADD MOVE TO PARMS AND IMPLICATE IT
    return (damage + wdamage + movdamage) * 2;

}
