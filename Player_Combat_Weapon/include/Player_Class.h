#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H
#include "Weapon_Class.h"
#include <vector>
#include "Moves_Class.h"
#include "Armor_Class.h"
#include "Food_Class.h"

class Player_Class
{
    public:
        Player_Class();
        Player_Class(std::string);
        Player_Class(std::string namee,int strengthh, int speedd, int defensee, int magicc, int thirstt, int levell);
        void setLevel(int);
        void LevelUP(Player_Class &);
        //holds moves and adds moves when you level up
        std::vector<Moves_Class> moveList;
        std::vector<Weapon_Class> weaponInventory;
        std::vector<Armor_Class> armorInventory;
        std::vector<Food_Class> foodInventory;
        //function to add moves to vector
        void checkMoveList(Player_Class&);
        //To display level during level up
        void displayLevel(Player_Class &, int str, int spd, int def, int mag, int lvl);
        //Player & operator=(Weapon &)
        //getters and setters
        int getStrength();
        int getSpeed();
        int getHealth();
        int getMagic();
        int getLevel();
        void setSpeed(int spdd);
        void setStrength(int strr);
        void setMagic(int magg);
        void setHealth(int deff);
        int setDamage();
        std::string getName();
        void deductDamage(int);

    protected:
        char resistance;
        int health;
        int exp_To_lvl = 100;
        int current_exp = 0;
        int strength, speed, magic, thirst, level;
        std::string name;

    private:
};

#endif // PLAYER_CLASS_H
