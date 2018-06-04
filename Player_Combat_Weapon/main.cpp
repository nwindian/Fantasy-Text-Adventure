#include <iostream>
#include <windows.h>
#include <rlutil.h>
#include "Combat_Event_Prototype.h"
#include "Player_Class.h"
#include "Weapon_Class.h"
#include "Moves_Class.h"
#include "Monster.hpp"
using namespace std;

int main()
{
    rlutil::setColor(2);
    rlutil::saveDefaultColor();
    Moves_Class move("Awesome move", 5,5);
    Moves_Class  moves("Awesome moves", 6,6);
    Moves_Class movess("Awesome movess", 6,6);
    Moves_Class movesss("Awesome movesss", 5,5);
    Weapon_Class sword(5, 'd', "sword");
    Weapon_Class axe(5,'d', "axe");
    Weapon_Class God(5,'l',"God Sword of Lightning");
    Weapon_Class Godd(5,'l',"God Sword of Lightning");
    Monster enemy("fish", 2, 2, 3, 0,0,2);
    Player_Class player("Joe",5,5,5,5,5,5);
    //player.LevelUP(player);

    //player.LevelUP(player);

//    rlutil::cls();
    //cin.get();
    player.moveList.push_back(move);
    player.moveList.push_back(moves);
    player.moveList.push_back(movess);
    //player.moveList.push_back(movesss);
    player.weaponInventory.push_back(sword);
    player.weaponInventory.push_back(axe);
    player.weaponInventory.push_back(God);
    //player.LevelUP(player);
    combat(player,enemy);
    return 0;
}
