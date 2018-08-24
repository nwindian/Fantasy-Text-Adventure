#ifndef COMBAT_EVENT_PROTOTYPE
#define COMBAT_EVENT_PROTOTYPE
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <limits>
#include <windows.h>
#include <memory>
#include "../include/Chance_To_Run.h"
#include "../include/Player_Class.h"
#include "../include/Monster.hpp"
#include "../include/Chance_Calc_Interface.h"
#include "../include/Damage_Calculator.h"
#include "../include/Weapon_Class.h"
#include "../include/Menu_Function.h"
#include "../include/Check_Inventory_Functions.h"
#include "../include/Show_Health.h"
#include "../include/Loading.h"
#include "../include/rlutil.h"

Weapon_Class getWeapon(Player_Class & );
bool whosQuicker(Player_Class & , Monster &);
int playerBP(Player_Class & , Monster &, int);
bool combat(Player_Class &, char);
void monsterBP(Monster & , Player_Class &, int&, int&, std::shared_ptr<Armor_Class>);
std::unique_ptr<Monster> spawnMonster(char);
void getExpFromBattle(Player_Class &, Monster &);
#endif // COMBAT_EVENT_PROTOTYPE
