#include <iostream>
#include <conio.h>
#include <iomanip>
#include <limits>
#include <windows.h>
#include "Upper_Bound.h"
#include "Player_Class.h"
#include "Monster.hpp"
#include "Chance_Calc_Interface.h"
#include "Damage_Calculator.h"
#include "Chance_Calc_Interface.h"
#include "Weapon_Class.h"
#include "rlutil.h"
#include "Menu_Function.h"
#include "Chance_To_Run.h"





Weapon_Class getWeapon(Player_Class & play)
{
    std::cout << "Choose a weapon my Player:" << std::endl;
    rlutil::setColor(6);
    bool repeat = false;
    unsigned int choice;
    int count = 0;
    for (unsigned int i = 0; i < play.weaponInventory.size(); ++i)
    {
        if (count == 5)
        {
            std::cout << std::endl;
            count = 0;
        }
        else
        {
            std::cout << i+1 << ": " << play.weaponInventory[i].getName() << " || ";
        }
    }
    std::cout << std::endl;
    while(repeat == false)
    {
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > play.weaponInventory.size())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Out of range boi" << std::endl;
        }
        else
        {
            repeat = true;
        }
    }
    return play.weaponInventory[choice -1];
}
//To check who is faster
bool whosQuicker(Player_Class & frnd, Monster & enem)
{
    if (frnd.getSpeed() > enem.getSpeed())
    {
        //return that the player is faster.
        return true;
    }
    else if (enem.getSpeed() > frnd.getSpeed())
    {
        return false;
    }
    else
    {
        return true;
    }
}
int playerBP(Player_Class & play, Monster & enem, int choice)
{
    bool repeat = true;
    int x = 23;
    int y = 7;
    unsigned int moveChoice;
    int upBound;
    rlutil::cls();
    rlutil::setColor(2);
    std::cout << "What would you like to do? " << std::endl;
    unsigned moveCount = 0;
    unsigned int count = 0;
    bool repeatChoice = true;
    bool repeatOne = true;
    int vecCounter = 0;
    //color
    rlutil::setColor(6);
    if (choice == 1)
    {
        rlutil::locate(70,1); std::cout << "Press b to go back or space to select." << std::endl;
        rlutil::locate(1,7);
        while(count < play.moveList.size())
        {
            std::cout << count + 1 << ") " << play.moveList[count].getName() << std::endl << std::endl;
            ++count;
        }
            upBound = Upper_bound(play.moveList);
            int l = upBound * 2;
            while (true) {
            rlutil::locate(x,y);
            rlutil::hidecursor();
            std::cout << " <--";
            if (!kbhit())
            {
                char k = getch(); // Get character
                rlutil::locate(x,y); std::cout << "     "; // Erase player
                if (k == 'w')
                {
                    if (y == 7)
                    {
                        moveCount = play.moveList.size();
                        y = y + l - 2;
                    }
                    else
                    {
                        --moveCount;
                        y = y - 2;
                    }
                }
                else if (k == 's')
                {
                    if (y == (play.moveList.size() * 2) + 5)
                    {
                        moveCount = 0;
                        y = 7;
                    }
                    else
                    {
                        ++moveCount;
                        y = y + 2;
                    }
                }
                else if (k == ' ')
                {
                    return moveCount;
                }
                else if (k == 'b')
                {
                    rlutil::cls();
                    return -1;
                }
            }
        }
    }
}

void MonsterBP(Monster & enemy, Player_Class & player)
{
    rlutil::cls();
    std::cout << "The " << enemy.getName() << " attacks!" << std::endl;
    for (int i = 0;i < 3; ++i)
    {
        std::cout << ". ";
        rlutil::msleep(600);
    }
    //rlutil::msleep(800);
    if (chanceM(enemy))
    {
        int damage = dmg_calc(player,enemy);
        player.deductDamage(damage);
        std::cout << damage << " health has been erased from you!" << std::endl;
    }
    else
    {
        std::cout << " Wow, he missed!" << std::endl;
    }

}
//Main function for Combat.
void combat(Player_Class & play,Monster & enem)
{
    int turnCount = 0;
    bool repeatFromB = true;
    bool repeatFromRun = true;
    int moveChoice;
    int damage;
    int playerHealth = play.getHealth();
    int enemyHealth = enem.getHealth();
    //health after the battle phase.
    int newPlayerHealth;
    int newEnemyHealth;
    std::cout << "You have entered combat with " << enem.getName() << "!!" << std::endl;
    //loop through battle until someone has 0 health (dies)
    Weapon_Class currentWeapon = getWeapon(play);
    while (play.getHealth() > 0 && enem.getHealth() > 0 && repeatFromRun == true)
    {
        repeatFromB = true;
        while (repeatFromB == true)
        {
            int choice = menu();
            if (choice == 1)
            {
                moveChoice = playerBP(play, enem, choice);
                if (whosQuicker(play, enem))
                {
                    if (moveChoice == -1)
                    {
                        repeatFromB = true;
                    }
                    else
                    {
                        rlutil::cls();
                        damage = dmg_calc(play, enem,currentWeapon, play.moveList[moveChoice]);
                        enem.deductDamage(damage);
                        std::cout << damage << std::endl;
                        repeatFromB = false;
                        rlutil::cls();
                        std::cout << enem.getName() << "'s turn!" << std::endl;
                        for (int i = 0;i < 3; ++i)
                        {
                            std::cout << ". ";
                            rlutil::msleep(600);
                        }
                        MonsterBP(enem,play);
                    }
                    repeatFromB = false;
                }
                else if (!whosQuicker(play,enem))
                {
                    MonsterBP(enem,play);
                    rlutil::msleep(1000);
                    rlutil::cls();
                    std::cout << "You have used " << play.moveList[moveChoice].getName() << std::endl;
                    for (int i = 0;i < 3; ++i)
                    {
                        std::cout << ". ";
                        rlutil::msleep(600);
                    }
                    damage = dmg_calc(play, enem,currentWeapon, play.moveList[moveChoice]);
                    std::cout << damage << " damage!!!";
                    enem.deductDamage(damage);
                    repeatFromB = false;
                }
            }
            else if (choice == 2)
            {

            }
            else if (choice == 3)
            {
                if (Chance_To_Run())
                {
                    std::cout << "You may be a wimp, but you sure are fast!";
                    repeatFromB = false;
                    repeatFromRun = false;
                }
                else
                {
                    std::cout << "Nope not today honey." << std::endl;
                    rlutil::msleep(800);
                    rlutil::cls();
                    repeatFromB = true;
                }
            }
            else if (choice == 4)
            {

            }
        }
    }
}
