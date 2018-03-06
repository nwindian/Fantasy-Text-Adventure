#ifndef COMBAT_EVENT_HPP_INCLUDED
#define COMBAT_EVENT_HPP_INCLUDED
#include <iostream>
#include "PlayerClass.h"

using std::cout;
using std::cin;
using std::endl;

void combat(Player & , Player &);
bool whosQuicker(Player &, Player &)

void combat(Player & play, Player & enem)
{
    cout << "You have entered combat with " << enem.getName << "!!" << endl;
    while (play.getHealth > 0 && enem.getHealth > 0)
    {

    }
}


#endif // COMBAT_EVENT_HPP_INCLUDED
