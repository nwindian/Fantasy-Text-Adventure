#include <iostream>
#include <fstream>
#include <map>
#include "../include/Monster.hpp"
#include "../include/Player_Class.h"
#include "../include/Weapon_Class.h"
#include "../include/Damage_Calculator.h"
#include "../include/Moves_Class.h"
#include "../include/Armor_Class.h"
#include "../../player/player.h"


double check_type(std::string att, std::string def)
{
    //E - Earth | P - Poison | F - Fire | I - Ice | S - Steel | D - Demon | H - Holy | L - Electric | B - Blood | W - Water
    std::string type = att + def;
    double dmg = player::types[type];
    return dmg;
}

int dmg_calc(Player_Class & player, Monster & enemy, Weapon_Class & weapon, Moves_Class  move)
{
    double type = check_type(move.getType(), enemy.getType());
    return (((player.getStrength() + weapon.getDmg()) / 10) + move.getDamage()) * type;
}

int dmg_calc(Player_Class & player, Monster & enemy, std::shared_ptr<Armor_Class> armor)
{
    std::string name = enemy.getName();
    double type = check_type(enemy.getType(), armor->getType());
    int damage = (enemy.getStrength() - ((armor->getArmor()/2))) * type;
    damage == 0 ? damage = 1 : damage = damage;
    return damage;
}


