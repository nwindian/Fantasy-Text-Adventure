#ifndef PLAYERCLASS_H_INCLUDED
#define PLAYERCLASS_H_INCLUDED

#include <iostream>
#include <limits>
#include "Weapon_Class.h"
using std::cout;
using std::string;
using std::endl;
using std::cin;
//Class for all Players
class Player
{
    private:
        Weapon weapon;
        int health;
        int exp_To_lvl = 100;
        int current_exp = 0;
        int strength, speed, magic, thirst, level;
        string name;

    public:
        int xLocation, yLocation;
        Player();
        Player(string namee,int strengthh, int speedd, int defensee, int xLocationn, int yLocationn, int magicc, int thirstt, int levell);
        void setLevel(int levelll);
        void LevelUP();
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
        string getName();
        void displayLevel( int str, int spd, int def, int mag, int lvl);
        void setWeapon(Weapon &);
};
//Default struct for Player Class
Player::Player()
{
    name = "Billiard";
    strength = 0;
    speed = 0;
    health = 0;
    xLocation = 0;
    yLocation = 0;
    magic = 0;
    thirst = 0;
    level = 1;
}
//Overloaded struct for Player class
Player::Player(string namee,int strengthh, int speedd, int defensee, int xLocationn, int yLocationn, int magicc, int thirstt, int levell)
{
    name = namee;
    strength = strengthh;
    speed = speedd;
    health = defensee;
    xLocation = xLocationn;
    yLocation = yLocationn;
    magic = magicc;
    thirst = thirstt;
    level = levell;

}
string Player::getName()
{
    return name;
}
// Mutator method for level in Player Class
void Player::setLevel(int levelll)
{
    level = levelll;
}
//Level
void Player::LevelUP()
{
    Player::setLevel(++level);
    std::cout << Player::getName() << " is now level " << Player::getLevel() << "! " << endl;
    Player::displayLevel(Player::getStrength(),Player::getSpeed(),Player::getHealth(),Player::getMagic(),Player::getLevel());
 }
//Getters and Setters
int Player::getHealth()
{
    return health;
}

int Player::getLevel()
{
    return level;
}

int Player::getMagic()
{
    return magic;
}

int Player::getStrength()
{
    return strength;
}

int Player::getSpeed()
{
    return speed;
}

void Player::setHealth(int deff)
{
    health = deff;
}

void Player::setStrength(int strr)
{
    strength = strr;
}

void Player::setSpeed(int spdd)
{
    speed = spdd;
}

void Player::setMagic(int magg)
{
    magic = magg;
}

void Player::displayLevel( int str, int spd, int def, int mag, int lvl)
{
    bool repeat = false;
    int counter = 0;
    //variable for player to choose which stat to level up
    int statup;
    //Prints current stats
    cout << "Awesome Adventurer: " << Player::getName() << endl << "Level: " << lvl << endl
        << "Current Stats: " << endl << "Strength: " << str << endl << "Speed: "
        << spd << endl << "Health: " << def << endl << "Magic: " << mag << endl;

    cout << endl << "--You have 3 points to put in your stats." << endl <<  "--Choose wisely, there are no take backs muahahahahahaha *cough cough*." << endl
        << "--Press 1 for point in strength, 2 for speed, 3 for Health, and 4 for magic(The only magic in this land is magic obtained from the sacred scrolls of Achimel, so if you don't have any, we'd recommend not upgrading this stat." << endl <<
            "--Pretty simple, especially for the likes of you." << endl;
    //Loop through to ask and assign stats to new stats
    for (int i = 0; i < 3; i++)
    {
        while (repeat == false)
        {
            cout << "Please choose stat to level up. " << endl;
            cin >> statup;
        if (cin.fail() || statup > 4 || statup < 1)
        {
            repeat = false;
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << endl << "Come on, just pick a valid stat. " << endl;
        }
        else
        {

            switch (statup)
            {
                case 1: ++str;
                        cout << "You have leveled up strength." << endl;
                        break;
                case 2: ++spd;
                        cout << "You have leveled up speed." << endl;
                        break;
                case 3: ++def;
                        cout << "You have leveled up Health." << endl;
                        break;
                case 4: ++mag;
                        cout << "You have leveled up magic." << endl;
                        break;
            }
            ++counter;
            if (counter == 3)
            {
                break;
            }
        }

    }
        //set everything to new stats
        Player::setHealth(def);
        Player::setMagic(mag);
        Player::setStrength(str);
        Player::setSpeed(spd);

        cout << "Your new stats: " << endl << "Strength: " << str << endl << "Speed: "
        << spd << endl << "Health: " << def << endl << "Magic: " << mag << endl;
        break;

        cout << "Press literally anything to continue your adventure. Just not the power button." << endl;
        cin.ignore();
        cin.get();
}
}
//Member function to set weapon of the player
void Player::setWeapon(Weapon & weap)
{
    weapon = weap;
}

#endif // PLAYERCLASS_H_INCLUDED
