#include <iostream>
#include <iomanip>
#include "../include/Show_Health.h"
#include "../include/rlutil.h"



void showHealth(Player_Class & player, Monster & enemy, int playHealth, int enemHealth)
{
    rlutil::locate(50,1); std::cout << player.getName() << "'s health:     ";
    rlutil::locate(50,2); std::cout << playHealth << "   / " << player.getHealth();
    rlutil::locate(50,3); std::cout << enemy.getName() << "'s health: ";
    rlutil::locate(50,4); std::cout << "                               ";
    rlutil::locate(50,4); std::cout << enemHealth << "   / " << enemy.getHealth();
}

void updateHealth(Player_Class & player, Monster & enemy, int playHealth, int enemHealth)
{
    if (playHealth < 1)
    {
        rlutil::locate(50,2);std::cout << "   ";
        rlutil::locate(50,2);std::cout << "  0";
        rlutil::locate(50,4);std::cout << "   ";
        rlutil::locate(50,4);std::cout << enemHealth;
    }
    else if (enemHealth < 1)
    {
        rlutil::locate(50,4);std::cout << "   ";
        rlutil::locate(50,4);std::cout << "  0";
        rlutil::locate(50,2);std::cout << "   ";
        rlutil::locate(50,2);std::cout << playHealth;
    }
    else
    {
        rlutil::locate(50,4);std::cout << "   ";
        rlutil::locate(50,4);std::cout << enemHealth;
        rlutil::locate(50,2);std::cout << "   ";
        rlutil::locate(50,2);std::cout << playHealth;
    }
}
