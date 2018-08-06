#ifndef COMBAT_EVENT_PROTOTYPE
#define COMBAT_EVENT_PROTOTYPE
#include <iostream>
#include <memory>
#include "Weapon_Class.h"
#include "Player_Class.h"
#include "Monster.hpp"
#include "Armor_Class.h"

Weapon_Class *getWeapon(Player_Class & );
bool whosQuicker(Player_Class & , Monster &);
int playerBP(Player_Class & , Monster &, int);
void combat(Player_Class & ,Monster & );
void monsterBP(Monster & , Player_Class &, int&, int&, std::shared_ptr<Armor_Class>);
#endif // COMBAT_EVENT_PROTOTYPE
