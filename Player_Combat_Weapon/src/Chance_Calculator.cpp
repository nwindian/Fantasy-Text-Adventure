#include <iostream>
#include <ctime>
#include <cstdlib>
<<<<<<< HEAD
#include "../include/Chance_Calc_Interface.h"
#include "../include/Moves_Class.h"
#include "../include/Player_Class.h"
bool chance(Player_Class & player,Moves_Class & mov)
=======
#include "Player_Class.h"
#include "Chance_Calc_Interface.h"
#include "Moves_Class.h"
bool chance(Player_Class & player,Moves_Class  mov)
>>>>>>> Player/Combat/Weapons
{
    srand(time(NULL));
    int chance = rand() % 100 + 1;
    if (chance > mov.getEvasive() && chance < 101)
    {
        return false;
    }
    return true;
}

bool chanceM(Monster & enemy)
{
    srand(time(NULL));
    int chance = rand() % 100 + 1;
    if (chance > enemy.getAccuracy() && chance < 101)
    {
        return true;
    }
    return false;
}
