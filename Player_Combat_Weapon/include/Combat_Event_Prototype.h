#ifndef COMBAT_EVENT_PROTOTYPE
#define COMBAT_EVENT_PROTOTYPE
#include "Weapon_Class.h"
#include "Player_Class.h"
#include "Monster.hpp"

Weapon_Class *getWeapon(Player_Class & play);
bool whosQuicker(Player_Class & frnd, Monster &);
int playerBP(Player_Class & play, Monster & enem, int);
void combat(Player_Class & play,Monster & enem);
int monsterBP(Monster & enem);
#endif // COMBAT_EVENT_PROTOTYPE
