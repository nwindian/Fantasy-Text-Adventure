#include <iostream>
#include "Monster.hpp"
#include "Player_Class.h"
#include "Weapon_Class.h"
#include "Damage_Calculator.h"
#include "Moves_Class.h"
#include "Armor_Class.h"



int dmg_calc(Player_Class & player, Monster & enemy, Weapon_Class & weapon, Moves_Class & move)
{
    char type = weapon.getType();
    //add resistance and type to total damage;
    return (player.getStrength() + weapon.getDmg() + move.getDamage()) * 2;
}

int dmg_calc(Player_Class & player, Monster & enemy)
{
    Armor_Class armor = player.getArmor();
    int arm = armor.getArmor();
    int strength = enemy.getStrength();
    std::string name = enemy.getName();
    return (enemy.getStrength() - armor.getArmor());
}
