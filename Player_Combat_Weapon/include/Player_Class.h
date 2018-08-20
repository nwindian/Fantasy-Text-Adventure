#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H
#include <iostream>
#include <limits>
#include <conio.h>
#include <vector>
#include "Weapon_Class.h"
#include "Moves_Class.h"
#include "Armor_Class.h"
#include "Food_Class.h"
#include "Monster.hpp"
#include "Weapon_Class.h"
#include "rlutil.h"

class Player_Class
{
    protected:
        std::vector<Moves_Class> moveList;
        std::vector<Weapon_Class> weaponInventory;
        std::vector<Armor_Class> armorInventory;
        std::vector<Food_Class> foodInventory;
        Armor_Class armor;
        char resistance;
        int health;
        int exp_to_lvl = 100;
        int current_exp = 0;
        int strength, speed, magic, thirst, level;
        std::string name;
    public:
        Player_Class();
        Player_Class(std::string);
        Player_Class(std::string namee,int strengthh, int speedd, int defensee, int magicc, int thirstt, int levell);
        void setLevel(int);
        void LevelUP(Player_Class &);
        //holds moves and adds moves when you level up
        //function to add moves to vector
        void checkMoveList(Player_Class&);
        //To display level during level up
        void displayLevel(Player_Class &, int str, int spd, int def, int mag, int lvl);
        //getters and setters
        const int getStrength();
        const int getSpeed();
        const int getHealth();
        const int getMagic();
        const int getLevel();
        const int getCExp();
        const int getMaxExp();
        const std::string getName();
        void setSpeed(int spdd);
        void setStrength(int strr);
        void setMagic(int magg);
        void setHealth(int deff);
        void setName(std::string);
        void setCExp(int);
        void setMaxExp();
        int setDamage();
        void deductDamage(int);
        void setArmor(Armor_Class &);
        Armor_Class getArmor();
        void updateXP();
        //vector stuff / Mostly inline
        void addFood(std::string name, int val){Food_Class food(val, name); foodInventory.push_back(food);}
        void addWeapon(Weapon_Class& weap){weaponInventory.push_back(weap);}
        void addArmor(Armor_Class& arm){armorInventory.push_back(arm);}
        void addMove(Moves_Class& move){moveList.push_back(move);}
        Food_Class get_Food(int i){return foodInventory[i];}
        Weapon_Class get_Weapon(int i){return weaponInventory[i];}
        Armor_Class get_Armor(int i){return armorInventory[i];}
        Moves_Class get_Move(int i){return moveList[i];}
        void erase_Food(int i){foodInventory.erase(foodInventory.begin() + i);}
        void erase_Weapon(int i){weaponInventory.erase(weaponInventory.begin() + i);}
        void erase_Armor(int i){armorInventory.erase(armorInventory.begin() + i);}
        void erase_Move(int i){moveList.erase(moveList.begin() + i);}
        int Wget_size(){return weaponInventory.size();}
        int Fget_size(){return foodInventory.size();}
        int Aget_size(){return armorInventory.size();}
        int Mget_size(){return moveList.size();}
        void cycle_weapon();
        void cycle_food();
        void cycle_armor();
        void cycle_moves();

    private:
};

#endif // PLAYER_CLASS_H
