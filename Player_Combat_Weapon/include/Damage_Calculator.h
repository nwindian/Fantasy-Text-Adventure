#ifndef DAMAGE_CALCULATOR_H_INCLUDED
#define DAMAGE_CALCULATOR_H_INCLUDED
#include "Monster.hpp"
#include "Type_Class.h"

int dmg_calc(Player_Class &, Monster & , Weapon_Class & , Moves_Class &);
int dmg_calc(Player_Class &, Monster &);
int check_type(Type_Class &, Type_Class &);


#endif // DAMAGE_CALCULATOR_H_INCLUDED
