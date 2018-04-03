#ifndef COMBAT_EVENT_HPP_INCLUDED
#define COMBAT_EVENT_HPP_INCLUDED
#include <iostream>
#include <conio.h>
#include "PlayerClass.h"
#include "Weapon_Class.h"

using std::cout;
using std::cin;
using std::endl;

void combat(Player & , Player &);
bool whosQuicker(Player &, Player &);
int playerPhase(Player &, Player &);
//To check who is faster
bool whosQuicker(Player & frnd, Player & enem)
{
    if (frnd.getSpeed() > enem.getSpeed())
    {
        //return that the player is faster.
        return true;
    }
    else if (enem.getSpeed() > frnd.getSpeed())
    {
        return false;
    }
    else
    {
        return true;
    }
}
//Players battle phase
int playerBP(Player & play, Player & enem)
{
    play.setDamage(play.);
    bool repeat = false;

}

void combat(Player & play, Player & enem)
{
    int playerHealth = play.getHealth();
    int enemyHealth = enem.getHealth();
    //health after the battle phase.
    int newPlayerHealth;
    int newEnemyHealth;
    cout << "You have entered combat with " << enem.getName << "!!" << endl;
    //loop through battle until someone has 0 health (dies)
    while (play.getHealth > 0 && enem.getHealth > 0)
    {
        if (whosQuicker(play, enem))
        {

        }
    }
}


#endif // COMBAT_EVENT_HPP_INCLUDED
