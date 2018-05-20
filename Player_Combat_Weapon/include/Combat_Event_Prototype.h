#ifndef COMBAT_EVENT_PROTOTYPE.H
#define COMBAT_EVENT_PROTOTYPE.H
Weapon_Class *getWeapon(Player_Class & play);
bool whosQuicker(Player_Class & frnd, Player_Class & enem);
int playerBP(Player_Class & play, Player_Class & enem);
void combat(Player_Class & play,Player_Class & enem);
#endif // COMBAT_EVENT_PROTOTYPE
