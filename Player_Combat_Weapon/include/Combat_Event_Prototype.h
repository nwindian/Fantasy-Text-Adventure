#ifndef COMBAT_EVENT_PROTOTYPE
#define COMBAT_EVENT_PROTOTYPE
#include "Weapon_Class.h"
#include "Player_Class.h"
Weapon_Class *getWeapon(Player_Class & play);
bool whosQuicker(Player_Class & frnd, Player_Class & enem);
int playerBP(Player_Class & play, Player_Class & enem, int);
void combat(Player_Class & play,Player_Class & enem);
#endif // COMBAT_EVENT_PROTOTYPE
