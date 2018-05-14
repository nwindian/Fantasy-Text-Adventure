#ifndef CHANCE_CALC_HPP_INCLUDED
#define CHANCE_CALC_HPP_INCLUDED
#include <stdlib.h>
#include <time.h>
bool chance(Player &, Moves&);
bool chance(Player & player,Moves & mov)
{
    srand(time(NULL));
    int chance = rand() % 100 + 1;
    if (chance > mov.getEvasive() && chance < 101)
    {
        return false;
    }
    return true;
}


#endif // CHANCE_CALC_HPP_INCLUDED
