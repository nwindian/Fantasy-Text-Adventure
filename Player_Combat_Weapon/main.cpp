#include <iostream>
#include <windows.h>
#include <rlutil.h>
#include "Combat_Event_Prototype.h"
#include "Player_Class.h"
#include "Weapon_Class.h"
#include "Moves_Class.h"
using namespace std;

int main()
{
    rlutil::setColor(2);
    rlutil::saveDefaultColor();
    Moves_Class move("Awesome move", 5,5);
    Moves_Class moves("Awesome moves", 5,5);
    Moves_Class movess("Awesome movess", 5,5);
    Weapon_Class sword(5, 'd', "sword");
    Player_Class enemy("fish", 2, 2, 3, 0,0,2);
    Player_Class player("Joe",5,5,5,5,5,5);
    player.LevelUP(player);
//    rlutil::cls();
    //cin.get();
    player.moveList.push_back(move);
    player.moveList.push_back(moves);
    player.moveList.push_back(movess);
    player.weaponInventory.push_back(sword);
    int a = playerBP(player, enemy);
   // player.LevelUP(player);
    return 0;
}
