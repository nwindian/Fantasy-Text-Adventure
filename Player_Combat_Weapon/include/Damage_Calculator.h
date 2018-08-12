#ifndef DAMAGE_CALCULATOR_H_INCLUDED
#define DAMAGE_CALCULATOR_H_INCLUDED
#include <iostream>
#include <memory>
#include "Monster.hpp"
void fillTypes();
int dmg_calc(Player_Class &, Monster & , Weapon_Class & , Moves_Class );
int dmg_calc(Player_Class &, Monster &, std::shared_ptr<Armor_Class>);
double check_type(std::string, std::string);


#endif // DAMAGE_CALCULATOR_H_INCLUDED
