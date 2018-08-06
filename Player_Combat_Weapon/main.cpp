#include <iostream>
#include <windows.h>
#include <rlutil.h>
#include "Combat_Event_Prototype.h"
#include "Player_Class.h"
#include "Monster.hpp"
#include "Weapon_Class.h"
#include "Moves_Class.h"
#include "Food_Class.h"

using namespace std;

int main()
{
    rlutil::setColor(2);
    rlutil::saveDefaultColor();
    Moves_Class move("Awesome move", 5,5,"F");
    Moves_Class  moves("Awesome moves", 6,6,"F");
    Moves_Class movess("Awesome movess", 6,6,"H");
    Moves_Class movesss("Awesome movesss", 5,5,"D");
    Weapon_Class sword(5, 'd', "sword");
    Weapon_Class axe(5,'d', "axe");
    Weapon_Class God(5,'l',"God Sword of Lightning");
    Food_Class  food(3, "chicken");
    Food_Class fd(4, "jalapeno");
    Food_Class fo(5, "pizza");
    Armor_Class armor(2, "Cool Armor", "I");
    Armor_Class armorr(2, "Cooler Armor", "I");
    Armor_Class armorrr(2, "Coolest Armor", "I");
    Monster enemy("fish", 1, 100, 3, 3,1,3,3,"I");
    Player_Class player("Joe",2,2,100,1,2,1);
    //player.LevelUP(player);
//    rlutil::cls();
    //cin.get();
    player.armorInventory.push_back(armor);
    player.armorInventory.push_back(armorr);
    player.armorInventory.push_back(armorrr);
    player.foodInventory.push_back(food);
    player.foodInventory.push_back(fd);
    player.foodInventory.push_back(fo);
    player.moveList.push_back(move);
    player.moveList.push_back(moves);
    player.moveList.push_back(movess);
    //player.moveList.push_back(movesss);
    player.weaponInventory.push_back(sword);
    player.weaponInventory.push_back(axe);
    player.weaponInventory.push_back(God);
   // player.LevelUP(player);
    combat(player,enemy);
    return 0;
}
