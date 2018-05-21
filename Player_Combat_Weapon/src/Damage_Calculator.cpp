#include <iostream>
#include "Player_Class.h"
#include "Weapon_Class.h"
#include "Damage_Calculator.h"


int dmg_calc(Player_Class & player, Player_Class & enemy, Weapon_Class & weapon)
{
    int damage = player.setDamage();
    int wdamage = weapon.getDmg();
    char type = weapon.getType();
    //add resistance and type to total damage;
    //ADD MOVE TO PARMS AND IMPLICATE IT
    return (damage + wdamage + (damage / 2)) * 2;

}
