#include <iostream>
#include <limits>
#include <conio.h>
#include <vector>
#include "../include/Moves_Class.h"
#include "../include/Armor_Class.h"
#include "../include/Weapon_Class.h"
#include "../include/Player_Class.h"
#include "../include/Monster.hpp"
#include "../include/rlutil.h"
//#include "Weapon_objects.hpp"


using std::cout;
using std::string;
using std::endl;
using std::cin;

//Default struct for Player Class
Player_Class::Player_Class()
{
    name = "Michael";
    strength = 1;
    speed = 1;
    health = 10;
    magic = 0;
    thirst = 0;
    level = 1;
    current_exp = 0;
    exp_to_lvl = 50;
}
//Overloaded struct for Player class

Player_Class::Player_Class(std::string namee, int strengthh, int speedd, int defensee, int magicc, int thirstt, int levell, int currExp, int futExp, int goldd)
{
    name = namee;
    strength = strengthh;
    speed = speedd;
    health = defensee;
    magic = magicc;
    thirst = thirstt;
    level = levell;
    current_exp = currExp;
    exp_to_lvl = futExp;
    gold = goldd;

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
    current_exp = 0;
    exp_to_lvl = 50;
    gold = 0;
}
const std::string Player_Class::getName()
{
    return name;
}
// Mutator method for level in Player Class
void Player_Class::setLevel(int levelll)
{
    level = levelll;
}

void Player_Class::setName(std::string namee)
{
    name = namee;
}
//Level
void Player_Class::LevelUP(Player_Class & player)
{
    Player_Class::setLevel(++level);
    std::cout << Player_Class::getName() << " is now level " << Player_Class::getLevel() << "! " << endl;
    Player_Class::displayLevel(player, player.getStrength(),player.getSpeed(),player.getHealth(),player.getMagic(),player.getLevel());
    Player_Class::updateXP();
    //checkMoveList(player);
 }
//Getters and Setters
const int Player_Class::getCExp()
{
    return current_exp;
}
const int Player_Class::getMaxExp()
{
    return exp_to_lvl;
}
const int Player_Class::getHealth()
{
    return health;
}
const int Player_Class::getLevel()
{
    return level;
}
const int Player_Class::getMagic()
{
    return magic;
}
const int Player_Class::getStrength()
{
    return strength;
}
const int Player_Class::getSpeed()
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
void Player_Class::setCExp(int xp)
{
    current_exp = xp;
}
void Player_Class::setMaxExp()
{
    exp_to_lvl = exp_to_lvl + 50;
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
    int x = 93;
    int y = 5;
    unsigned int counter = 0;
    //Prints current stats
    rlutil::setColor(3);
    rlutil::locate(0,0); std::cout << "Awesome Adventurer: " << player.getName();
    rlutil::locate(80, 2); std::cout << "Level: " << lvl;
    rlutil::locate(80,4); std::cout<< "Current Stats: ";
    rlutil::locate(80,5); std::cout << "Strength: " << str;
    rlutil::locate(80,7); std::cout << "Speed: " << spd;
    rlutil::locate(80,9); std::cout << "Health: " << def;
    rlutil::locate(80,11); std::cout << "Magic: " << mag;
    rlutil::resetColor();
    rlutil::setColor(2);
    rlutil::locate(1,3); std::cout << "--You have 3 points to put in your stats." << std::endl <<  "--Choose wisely, there are no take backs muahahahahahaha *cough cough*." << endl
        << "--Press 1 for point in strength, 2 for speed, 3 for Health, and 4 for magic \n--(The only magic in this land is magic obtained from the sacred scrolls of \n--Achimel, so if you don't have any, we'd recommend not upgrading this stat.)" << endl <<
            "--Pretty simple, especially for the likes of you." << std::endl;
    //Loop through to ask and assign stats to new stats
    std::cout << "--Please choose stat to level up. Press the space bar to\n--finalize your decision. " << std::endl;
    while (counter < 3)
    {
        while (true)
        {
            rlutil::locate(x,y);
            rlutil::hidecursor();
            std::cout << "  <--";
            //rlutil::locate(1,4); std::cout << "Turn count: " << cnt;
            if (kbhit()) {
                char k = getch(); // Get character
                rlutil::locate(x,y); std::cout << "     "; // Erase player
                if (k == 'w')
                {
                    if (y == 5)
                    {
                        y = y + 6;
                    }
                    else
                    {
                        y = y - 2;
                    }
                }
                else if (k == 's')
                {
                    if (y == 11)
                    {
                        y = y - 6;
                    }
                    else
                    {
                        y = y + 2;
                    }
                }
                else if (k == ' ')
                {
                    if (y == 5)
                    {
                        ++counter;
                        ++str;
                        rlutil::locate(90,5);
                        std::cout << " ";
                        rlutil::locate (90,5);
                        player.setStrength(str);
                        rlutil::setColor(3);
                        std::cout << str;
                        break;
                    }
                    else if(y == 7)
                    {
                        ++counter;
                        ++spd;
                        rlutil::locate(87,7);
                        std::cout << " ";
                        rlutil::locate (87,7);
                        player.setSpeed(spd);
                        rlutil::setColor(3);
                        std::cout << spd;
                        break;
                    }
                    else if(y == 9)
                    {
                        ++counter;
                        ++def;
                        rlutil::locate(88,9);
                        std::cout << " "; rlutil::setColor(3);
                        rlutil::locate (88,9);
                        player.setHealth(def);
                        rlutil::setColor(3);
                        std::cout << def;
                        break;
                    }
                    else if (y == 11)
                    {
                        ++counter;
                        ++mag;
                        rlutil::locate(87,11);
                        std::cout << " ";
                        rlutil::locate (87,11);
                        player.setMagic(mag);
                        rlutil::setColor(3);
                        std::cout << mag;
                        break;
                    }
                }
                //rlutil::locate(x,y); std::cout << '@'; // Output player
            }
        }
    }
    rlutil::locate(1,11);
    std::cout << "Your new stats: " << endl;
    rlutil::setColor(3); std::cout << "Strength: " << str << endl << "Speed: "
            << spd << endl << "Health: " << def << endl << "Magic: " << mag << endl;
    rlutil::setColor(2);
    std::cout << "Press literally anything to continue your adventure. Just not the power button." << endl;
    std::cin.ignore();
    std::cin.get();
}
//Now create copy constructor
//Check the move list to add moves if levelled up.
void Player_Class::checkMoveList(Player_Class & player)
{
    if (player.getLevel() == 2)
    {
        Moves_Class move("Fury", 10, 90, "N");
        moveList.push_back(move);
        cout << endl << "You have obtained a new move called Fury! Pretty basic and yet very exciting! Right now all it does is " << move.getDamage() << " damage!" << endl;
    }
}

void Player_Class::deductDamage(int damage)
{
    Player_Class::setHealth(Player_Class::getHealth() - damage);
}

Armor_Class Player_Class::getArmor()
{
    return armor;
}

void Player_Class::setArmor(Armor_Class & arm)
{
    armor = arm;
}

void Player_Class::cycle_armor()
{
    for(int i = 0; i < armorInventory.size(); ++i)
    {
        std::cout << i + 1 << ") " << armorInventory[i].getName() << std::endl;
    }
}

void Player_Class::cycle_food()
{
    for(int i = 0; i < foodInventory.size(); ++i)
    {
        std::cout << i + 1 << ") " << foodInventory[i].getName() << std::endl;
    }
}

void Player_Class::cycle_moves()
{
    for(int i = 0; i < moveList.size(); ++i)
    {
        std::cout << i + 1 << ") " << moveList[i].getName() << std::endl;
    }
}

void Player_Class::cycle_weapon()
{
    for(int i = 0; i < weaponInventory.size(); ++i)
    {
        std::cout << i + 1 << ") " << weaponInventory[i].getName() << std::endl;
    }
}

void Player_Class::updateXP()
{
    if(Player_Class::current_exp >= Player_Class::exp_to_lvl)
    {
        Player_Class::setCExp(Player_Class::exp_to_lvl - Player_Class::current_exp);
        Player_Class::setMaxExp();
    }
}

void Player_Class::addGold(int goldd)
{
    gold = goldd;
}
void Player_Class::subtractGold(int goldd)
{
    gold = goldd;
}
