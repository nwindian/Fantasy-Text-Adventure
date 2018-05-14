#ifndef PLAYER_CLASS_INTERFACE_H_INCLUDED
#define PLAYER_CLASS_INTERFACE_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
using std::string;
class Player
{
    private:
        char resistance;
        int health;
        int exp_To_lvl = 100;
        int current_exp = 0;
        int strength, speed, magic, thirst, level;

        string name;
    public:
        Player(string);
        Player();
        Player(string namee,int strengthh, int speedd, int defensee, int magicc, int thirstt, int levell);
        void setLevel(int levelll);
        void LevelUP(Player &);
        Armor armor;
        //holds moves and adds moves when you level up
        std::vector<Moves> moveList;
        std::vector<Weapon> weaponInventory;
        std::vector<Armor> armorInventory;
        //function to add moves to vector
        void checkMoveList(Player&);
        //To display level during level up
        void displayLevel(Player &, int str, int spd, int def, int mag, int lvl);
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
        int setDamage(Weapon &);
        string getName();
};


#endif // PLAYER_CLASS_INTERFACE_H_INCLUDED
