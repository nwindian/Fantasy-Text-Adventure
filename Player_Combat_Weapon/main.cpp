#include <iostream>
#include "rlutil.h"
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
    Armor_Class armorrr(2, "Coolest Armor", "W");
    Monster enemy("fish", 1, 100, 3, 3,1,3,3,"F");
    Player_Class player("Joe",2,2,100,1,2,1);
    //player.LevelUP(player);
//    rlutil::cls();
    //cin.get();
    player.addArmor(armor);
    player.addArmor(armorr);
    player.addArmor(armorr);
    player.addFood(food);
    player.addFood(fd);
    player.addFood(fo);
    player.addMove(move);
    player.addMove(moves);
    player.addMove(movess);
    //player.moveList.push_back(movesss);
    player.addWeapon(sword);
    player.addWeapon(axe);
    player.addWeapon(God);
   // player.LevelUP(player);
   char f = 'F';
    combat(player,f );
    return 0;
}
