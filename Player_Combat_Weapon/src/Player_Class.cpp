#include <iostream>
#include <limits>
#include <conio.h>
#include <vector>
#include "Moves_Class.h"
#include "Armor_Class.h"
#include "Weapon_Class.h"
#include "Player_Class.h"
//#include "Weapon_objects.hpp"


using std::cout;
using std::string;
using std::endl;
using std::cin;

//Default struct for Player Class
Player_Class::Player_Class()
{
    name = "Michael";
    strength = 0;
    speed = 0;
    health = 0;
    magic = 0;
    thirst = 0;
    level = 1;
    resistance = '0';
}
//Overloaded struct for Player class

Player_Class::Player_Class(std::string namee,int strengthh, int speedd, int defensee, int magicc, int thirstt, int levell)
{
    name = namee;
    strength = strengthh;
    speed = speedd;
    health = defensee;
    magic = magicc;
    thirst = thirstt;
    level = levell;

}
Player_Class::Player_Class(std::string namee)
{
    name = namee;
    strength = 0;
    speed = 0;
    health = 0;
    magic = 0;
    thirst = 0;
    level = 1;
}
std::string Player_Class::getName()
{
    return name;
}
// Mutator method for level in Player Class
void Player_Class::setLevel(int levelll)
{
    level = levelll;
}
//Level
void Player_Class::LevelUP(Player_Class & player)
{
    Player_Class::setLevel(++level);
    std::cout << Player_Class::getName() << " is now level " << Player_Class::getLevel() << "! " << endl;
    Player_Class::displayLevel(player, player.getStrength(),player.getSpeed(),player.getHealth(),player.getMagic(),player.getLevel());
    std::cin.ignore();
    std::cin.get();
    checkMoveList(player);
 }
//Getters and Setters
int Player_Class::getHealth()
{
    return health;
}
int Player_Class::getLevel()
{
    return level;
}
int Player_Class::getMagic()
{
    return magic;
}
int Player_Class::getStrength()
{
    return strength;
}
int Player_Class::getSpeed()
{
    return speed;
}
void Player_Class::setHealth(int deff)
{
    health = deff;
}
void Player_Class::setStrength(int strr)
{
    strength = strr;
}
void Player_Class::setSpeed(int spdd)
{
    speed = spdd;
}
void Player_Class::setMagic(int magg)
{
    magic = magg;
}
//Set the total damage for the level
int Player_Class::setDamage()
{
    int playerStrength = Player_Class::getStrength();
    //int weapDamage = Player_Class::weapon.getDmg();
    //char type =
    double div = playerStrength / 2;
    return (playerStrength  + div) * 2;
}
//Displays the players level with his stats
void Player_Class::displayLevel( Player_Class & player, int str, int spd, int def, int mag, int lvl)
{
    bool repeat = false;
    int counter = 0;
    //variable for player to choose which stat to level up
    int statup;
    //Prints current stats
    std::cout << "Awesome Adventurer: " << player.getName() << std::endl << "Level: " << lvl << std::endl
        << "Current Stats: " << endl << "Strength: " << str << endl << "Speed: "
        << spd << std::endl << "Health: " << def << std::endl << "Magic: " << mag << std::endl;

    std::cout << std::endl << "--You have 3 points to put in your stats." << std::endl <<  "--Choose wisely, there are no take backs muahahahahahaha *cough cough*." << endl
        << "--Press 1 for point in strength, 2 for speed, 3 for Health, and 4 for magic \n--(The only magic in this land is magic obtained from the sacred scrolls of \n--Achimel, so if you don't have any, we'd recommend not upgrading this stat." << endl <<
            "--Pretty simple, especially for the likes of you." << std::endl;
    //Loop through to ask and assign stats to new stats
    for (int i = 0; i < 3; i++)
    {
        while (repeat == false)
        {
            std::cout << "Please choose stat to level up. " << std::endl;
            std::cin >> statup;
            if (std::cin.fail() || statup > 4 || statup < 1)
            {
                repeat = false;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << std::endl << "Come on, just pick a valid stat. " << std::endl;
            }
            else
            {
                switch (statup)
                {
                    case 1: ++str;
                            std::cout << "You have leveled up strength." << std::endl;
                            break;
                    case 2: ++spd;
                            std::cout << "You have leveled up speed." << std::endl;
                            break;
                    case 3: ++def;
                            std::cout << "You have leveled up Health." << std::endl;
                            break;
                    case 4: ++mag;
                            std::cout << "You have leveled up magic." << std::endl;
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
        player.setHealth(def);
        player.setMagic(mag);
        player.setStrength(str);
        player.setSpeed(spd);

        cout << "Your new stats: " << endl << "Strength: " << str << endl << "Speed: "
        << spd << endl << "Health: " << def << endl << "Magic: " << mag << endl;
        break;

        cout << "Press literally anything to continue your adventure. Just not the power button." << endl;
        cin.ignore();
        cin.get();
    }
}
//Now create copy constructor
//Check the move list to add moves if levelled up.
void Player_Class::checkMoveList(Player_Class & player)
{
    if (player.getLevel() == 2)
    {
        Moves_Class move("Fury", 10, 90);
        moveList.push_back(move);
        cout << endl << "You have obtained a new move called Fury! Pretty basic and yet very exciting! Right now all it does is " << move.getDamage() << " damage!" << endl;
    }
}
