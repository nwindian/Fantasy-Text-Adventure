#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include "../include/Weapon_Class.h"
#include "../include/Get_Random_Equipment.h"


Weapon_Class& getRandomWeapon(Player_Class& player)
{
    std::vector<char> typeVec = {'E','P','F','I','S','D','H','L','B','W'};
//    std::map<char,std::vector> typeWeaponName;
//    std::vector<string> weaponNames;
    char type;
    Weapon_Class newWeapon;
//    newWeapon.get
    srand(time(NULL));
    int randomStrength = (rand() % (player.getLevel() + 10)) + 1;
    newWeapon.setDmg(randomStrength);
//    int newWeapon.get
    int typeRarityNum =(rand() % (11));
    if(typeRarityNum < 8)
    {
        int randomTypeNum =(rand() % (9));
        type = typeVec[randomTypeNum];
//        newWeapon.setType(typeVec);
    }
    else
    {
        int randomTypeNum =(rand() % (3)) + 8;
        type = typeVec[randomTypeNum];
//        newWeapon.setType(typeVec);
    }
    char randomType;
}
