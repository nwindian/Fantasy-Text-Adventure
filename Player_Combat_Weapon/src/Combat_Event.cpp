#include <iostream>
#include <conio.h>
#include <iomanip>
#include <limits>
#include <windows.h>
#include <memory>
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
#include "Check_Inventory_Functions.h"
#include "Show_Health.h"
#include "Loading.h"




Weapon_Class getWeapon(Player_Class & play)
{
    rlutil::setColor(6);
    std::cout << "Choose a weapon my Player:" << std::endl;
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
    return play.weaponInventory[choice - 1];
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
    int y = 2;
    unsigned int moveChoice;
    int upBound;
    rlutil::cls();
    showHealth(play,enem,play.getHealth(),enem.getHealth());
    rlutil::setColor(2);
    rlutil::locate(1,1); std::cout << "What would you like to do? " << std::endl;
    unsigned moveCount = 0;
    unsigned int count = 0;
    bool repeatChoice = true;
    bool repeatOne = true;
    int vecCounter = 0;
    //color
    rlutil::setColor(6);
    if (choice == 1)
    {
        unsigned int count = 0;
        bool repeatChoice = true;
        rlutil::resetColor();
        rlutil::locate(40,10); std::cout << "**Press b to go back or space to select." << std::endl;
        rlutil::setColor(6);
        while(count < play.moveList.size())
        {
            rlutil::locate(1,count + 2);
            std::cout << count + 1 << ") " << play.moveList[count].getName() << std::endl << std::endl;
            ++count;
        }
        rlutil::resetColor();
        if (choice == 1)
        {
            for(int i = 0;i < 30; ++ i)
            {
                rlutil::locate(i+1, 1);
                std::cout << "_";
            }
            for (int i = 0; i < play.moveList.size() + 2; ++i)
            {
                rlutil::locate(31,i+2);
                std::cout << "|";
            }
            for(int i = 0;i < 30; ++ i)
            {
                rlutil::locate(i+1, play.moveList.size()+3);
                std::cout << "_";
            }
            //rlutil::locate(1,3);
            upBound = Upper_bound(play.moveList);
            int l = upBound * 2;
            while (true)
            {
                rlutil::locate(x,y);
                rlutil::hidecursor();
                rlutil::resetColor();
                std::cout << " <--";
                if (!kbhit())
                {
                    char k = getch(); // Get character
                    rlutil::locate(x,y); std::cout << "     "; // Erase player
                    if (k == 'w')
                    {
                        if (y == 2)
                        {
                            moveCount = play.moveList.size();
                            y = (play.moveList.size() + 1);
                        }
                        else
                        {
                            --moveCount;
                            y = y - 1;
                        }
                    }
                    else if (k == 's')
                    {
                        if (y == (play.moveList.size() + 1))
                        {
                            moveCount = 0;
                            y = 2;
                        }
                        else
                        {
                            ++moveCount;
                            y = y + 1;
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
}

int MonsterBP(Monster & enemy, Player_Class & player)
{
    rlutil::resetColor();
    rlutil::cls();
    showHealth(player,enemy,player.getHealth(),enemy.getHealth());
    rlutil::locate(1,1);
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
        std::cout << std::endl << damage << " health has been erased from you!" << std::endl;
        return damage;
    }
    else
    {
        std::cout << " Wow, he missed!" << std::endl;
    }

}
//Main function for Combat.
void combat(Player_Class & play,Monster & enem)
{
    rlutil::setColor(2);
    rlutil::saveDefaultColor();
    int x = 40;
    int y = 2;
    int moveCount = 0;
    int turnCount = 0;
    bool repeatFromB = true;
    bool repeatFromRun = true;
    int moveChoice;
    int damage;
    int mdamage;
    int currentHealth = play.getHealth();
    int currentEHealth = enem.getHealth();
    //health after the battle phase.
    int newPlayerHealth;
    int newEnemyHealth;
    rlutil::cls();
    showHealth(play,enem,currentHealth,currentEHealth);
    rlutil::locate(1,1);
    std::cout << "You have entered combat with " << enem.getName() << "!!" << std::endl;
    //FOR WEAPON
    std::unique_ptr<Weapon_Class> currentWeapon(new Weapon_Class);
    rlutil::setColor(6);
    for (int i = 0; i < play.weaponInventory.size(); ++i)
    {
        std::cout << i + 1 << ") " << play.weaponInventory[i].getName() << std::endl;
    }
    //color
    rlutil::setColor(2);
    rlutil::locate(40,10); std::cout << "**Press b to go back or space to select." << std::endl;
    rlutil::resetColor();
    while (true)
    {
        rlutil::locate(x,y);
        rlutil::hidecursor();
        std::cout << " <--";
        if (!kbhit())
        {
            char k = getch(); // Get character
            rlutil::locate(x,y); std::cout << "     "; // Erase player
            if (k == 'w')
            {
                if (y == 2)
                {
                    moveCount = play.weaponInventory.size();
                    y = (play.moveList.size() + 1);
                }
                else
                {
                    --moveCount;
                    y = y - 1;
                }
            }
            else if (k == 's')
            {
                if (y == (play.weaponInventory.size() + 1))
                {
                    moveCount = 0;
                    y = 2;
                }
                else
                {
                    ++moveCount;
                    y = y + 1;
                }
            }
            else if (k == ' ')
            {
                *currentWeapon = play.weaponInventory[moveCount];
                break;
            }
        }
    }
    rlutil::cls();
    //Weapon_Class currentWeapon = getWeapon(play);
    while (currentHealth > 0 && currentEHealth > 0 && repeatFromRun == true)
    {
        repeatFromB = true;
        while (repeatFromB == true)
        {
            showHealth(play,enem,currentHealth,currentEHealth);
            rlutil::locate(1,1);
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
                        showHealth(play,enem,currentHealth,currentEHealth);
                        damage = dmg_calc(play, enem,*currentWeapon, play.moveList[moveChoice]);
                        if(chance(play, play.moveList[moveChoice]))
                        {
                            currentEHealth = currentEHealth - damage;
                            std::cout << damage << std::endl;
                            updateHealth(play,enem,currentHealth,currentEHealth);
                            repeatFromB = false;
                            rlutil::msleep(500);
                            rlutil::cls();
                            showHealth(play,enem,currentHealth,currentEHealth);
                        }
                        else
                        {
                            std::cout << "You missed. May need some glasses.";
                            rlutil::msleep(500);
                            rlutil::cls();
                            showHealth(play,enem,currentHealth,currentEHealth);

                        }
                        if (currentEHealth < 1)
                        {
                            std::cout << "You have defeated " << enem.getName() << "!!" << std::endl;
                            repeatFromB = false;
                            loading_Six();
                        }
                        else
                        {
                            std::cout << enem.getName() << "'s turn!" << std::endl;
                            for (int i = 0;i < 3; ++i)
                            {
                                std::cout << ". ";
                                rlutil::msleep(600);
                            }
                            mdamage = MonsterBP(enem,play);
                            currentHealth = currentHealth - mdamage;
                            if (currentHealth < 1)
                            {
                                std::cout << "You have been defeated!! Not entirely surprising!!" << std::endl;
                                repeatFromB = false;
                            }
                        }
                    repeatFromB = false;
                }
            }
                else if (!whosQuicker(play,enem))
                {

                    if (moveChoice == -1)
                    {
                        repeatFromB = true;
                    }
                    else
                    {
                        mdamage = MonsterBP(enem,play);
                        currentHealth = currentHealth - mdamage;
                        updateHealth(play,enem,currentHealth,currentEHealth);
                        if (currentHealth < 1)
                        {
                            rlutil::locate(1,5); std::cout << "You have been defeated!! Not entirely surprising!!" << std::endl;
                            repeatFromB = false;
                            rlutil::msleep(4000);
                        }
                        else
                        {
                            rlutil::msleep(1000);
                            rlutil::cls();
                            showHealth(play,enem,currentHealth,currentEHealth);
                            std::cout << "You have used " << play.moveList[moveChoice].getName() << std::endl;
                            for (int i = 0;i < 3; ++i)
                            {
                                std::cout << ". ";
                                rlutil::msleep(600);
                            }
                            damage = dmg_calc(play, enem,*currentWeapon, play.moveList[moveChoice]);
                            std::cout << damage << " damage!!!" << std::endl;
                            currentEHealth = currentEHealth - damage;
                            updateHealth(play,enem,currentHealth,currentEHealth);
                            if (currentEHealth < 1)
                            {
                                std::cout << "You have defeated " << enem.getName() << "!!" << std::endl;
                                repeatFromB = false;
                                loading_Six();
                            }
                            repeatFromB = false;
                        }
                    }
                }
            }
            else if (choice == 2)
            {
                int k = -1;
                int check = 0;
                while(k == -1)
                {
                    rlutil::cls();
                    showHealth(play,enem,currentHealth,currentEHealth);
                    int inv = getInventory();
                    if (inv == 0)
                    {
                        k = getFromInventoryF(play);
                        check = 1;
                    }
                    else if (inv == 1)
                    {
                        k = getFromInventoryW(play);
                        check = 2;
                    }
                    else
                    {
                        repeatFromB = true;
                        break;
                    }
                }
                if (check == 1)
                {
                    std::cout << "You have healed " << play.foodInventory[k].getAmount() << "." << std::endl;
                    updateHealth(play,enem,currentHealth,currentEHealth);
                    play.foodInventory.erase(play.foodInventory.begin() + k);
                    rlutil::msleep(700);
                    repeatFromB = false;
                }
                else if (check == 2)
                {
                    std::cout << "Your new equipped weapon is " << play.weaponInventory[k].getName() << "!" << std::endl;
                    *currentWeapon = play.weaponInventory[k];
                    rlutil::msleep(700);
                    repeatFromB = false;
                }
            }
            else if (choice == 3)
            {
                if (Chance_To_Run())
                {
                    std::cout << "You may be a wimp, but you sure are fast!";
                    rlutil::msleep(800);
                    repeatFromB = false;
                    repeatFromRun = false;
                }
                else
                {
                    std::cout << "Nope not today honey." << std::endl;
                    rlutil::msleep(800);
                    rlutil::cls();
                    showHealth(play,enem,currentHealth,currentEHealth);
                    repeatFromB = true;
                }
            }
        }
    }
}
