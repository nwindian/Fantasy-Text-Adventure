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
int playerBP(Player_Class & play, Monster & enem, int choice, int health, int mHealth)
{
    int x = 23;
    int y = 2;
    rlutil::cls();
    showHealth(play,enem,health,mHealth);
    rlutil::setColor(2);
    rlutil::locate(1,1); std::cout << "What would you like to do? " << std::endl;
    unsigned moveCount = 0;
    //color
    rlutil::setColor(6);
    if (choice == 1)
    {
        unsigned int count = 0;
        rlutil::resetColor();
        rlutil::locate(40,10); std::cout << "**Press b to go back or Enter to select." << std::endl;
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
            for(unsigned int i = 0;i < 30; ++i)
            {
                rlutil::locate(i+1, 1);
                std::cout << "_";
            }
            for (unsigned int i = 0; i < play.moveList.size() + 2; ++i)
            {
                rlutil::locate(31,i+2);
                std::cout << "|";
            }
            for(unsigned int i = 0;i < 30; ++ i)
            {
                rlutil::locate(i+1, play.moveList.size()+3);
                std::cout << "_";
            }
            //rlutil::locate(1,3);
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
                    else if (k == '\r')
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

int MonsterBP(Monster & enemy, Player_Class & player, int & currentHealth, int & currentEHealth, std::shared_ptr<Armor_Class> armor)
{
    rlutil::resetColor();
    rlutil::cls();
    showHealth(player,enemy,currentHealth,currentEHealth);
    rlutil::locate(1,1);
    std::cout << "The " << enemy.getName() << " attacks!" << std::endl;
    loading_Six();
    //rlutil::msleep(800);
    if (chanceM(enemy))
    {
        int damage = dmg_calc(player,enemy,armor);
        currentHealth = currentHealth - damage;
        std::cout << std::endl << damage << " health has been erased from you!" << std::endl;
        loading_Six();
        return currentHealth;
    }
    else
    {
        std::cout << " Wow, he missed!" << std::endl;
        loading_Six();
        return 0;
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
    bool repeatFromB = true;
    bool repeatFromRun = true;
    int moveChoice;
    int damage;
    int mdamage;
    int currentHealth = play.getHealth();
    int currentEHealth = enem.getHealth();
    //health after the battle phase.
    rlutil::cls();
    showHealth(play,enem,currentHealth,currentEHealth);
    rlutil::locate(1,1);
    std::cout << "You have entered combat with " << enem.getName() << "!!" << std::endl;
    //FOR WEAPON
    std::unique_ptr<Weapon_Class> currentWeapon(new Weapon_Class);
    std::shared_ptr<Armor_Class> currentArmor(new Armor_Class);
    rlutil::setColor(6);
    for (unsigned int i = 0; i < play.weaponInventory.size(); ++i)
    {
        std::cout << i + 1 << ") " << play.weaponInventory[i].getName() << std::endl;
    }
    //color
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
                    y = (play.weaponInventory.size() + 1);
                }
                else
                {
                    --moveCount;
                    y = y - 1;
                }
            }
            else if (k == '\r')
            {
                *currentWeapon = play.weaponInventory[moveCount];
                rlutil::cls();
                break;
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
        }
    }
    x = 40; y = 2;
    moveCount = 0;
    std::cout << "Now choose your armor: " << std::endl;
    rlutil::setColor(4);
    for (unsigned int i = 0; i < play.armorInventory.size(); ++i)
    {
        std::cout << i + 1 << ") " << play.armorInventory[i].getName() << std::endl;
    }
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
                    moveCount = play.armorInventory.size();
                    y = (play.armorInventory.size() + 1);
                }
                else
                {
                    --moveCount;
                    y = y - 1;
                }
            }
            else if (k == '\r')
            {
                *currentArmor = play.armorInventory[moveCount];
                break;
            }
            else if (k == 's')
            {
                if (y == (play.armorInventory.size() + 1))
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
        }
    }
    //Weapon_Class currentWeapon = getWeapon(play);
    while (currentHealth > 0 && currentEHealth > 0 && repeatFromRun == true)
    {
        repeatFromB = true;
        while (repeatFromB == true)
        {
            //rlutil::msleep(1000);
            rlutil::cls();
            showHealth(play,enem,currentHealth,currentEHealth);
            rlutil::locate(1,1);
            int choice = menu();
            if (choice == 1)
            {
                moveChoice = playerBP(play, enem, choice, currentHealth, currentEHealth);
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
                        rlutil::locate(1,1);
                        std::cout << "You have used " << play.moveList[moveChoice].getName() << "!" << std::endl;
                        loading_Six();
                        if(chance(play, play.moveList[moveChoice]))
                        {
                            rlutil::locate(1,1);
                            currentEHealth = currentEHealth - damage;
                            std::cout << std::endl << damage << " damage" << std::endl;
                            updateHealth(play,enem,currentHealth,currentEHealth);
                            rlutil::locate(1,1);
                            repeatFromB = false;
                            rlutil::msleep(500);
                            rlutil::cls();
                            showHealth(play,enem,currentHealth,currentEHealth);
                        }
                        else
                        {
                            rlutil::locate(1,1);
                            std::cout << "You missed. May need some glasses.";
                            rlutil::msleep(1000);
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
                            rlutil::locate(1,1);
                            std::cout << enem.getName() << "'s turn!" << std::endl;
                            loading_Six();
                            mdamage = MonsterBP(enem,play,currentHealth,currentEHealth, currentArmor);
                            updateHealth(play,enem,currentHealth,currentEHealth);
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
                        mdamage = MonsterBP(enem,play,currentHealth, currentEHealth, currentArmor);
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
                            rlutil::locate(1,1);
                            std::cout << "You have used " << play.moveList[moveChoice].getName() << std::endl;
                            loading_Six();
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
                int inv = 0;
                int k = -1;
                int check = 0;
                while(k == -1)
                {
                    rlutil::cls();
                    inv = getInventory(play, enem, currentHealth,currentEHealth);
                    showHealth(play,enem,currentHealth,currentEHealth);
                    rlutil::locate(1,1);
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
                    else if (inv == 2)
                    {
                        k = getFromInventoryA(play);
                        check = 3;
                    }
                    else
                    {
                        repeatFromB = true;
                        break;
                    }
                }
                if (inv == -1)
                {
                    repeatFromB = true;
                }
                else if (check == 1)
                {
                    std::cout << "You have healed " << play.foodInventory[k].getAmount() << "." << std::endl;
                    currentHealth = currentHealth + play.foodInventory[k].getAmount();
                    if(currentHealth > play.getHealth())
                    {
                        currentHealth = play.getHealth();
                    }
                    showHealth(play,enem,currentHealth,currentEHealth);
                    updateHealth(play,enem,currentHealth,currentEHealth);
                    play.foodInventory.erase(play.foodInventory.begin() + k);
                    rlutil::msleep(2000);
                    repeatFromB = false;
                    mdamage = MonsterBP(enem,play,currentHealth, currentEHealth,currentArmor);
                    updateHealth(play,enem,currentHealth,currentEHealth);
                    rlutil::locate(1,4);
                    rlutil::msleep(200);
                    loading_Six();
                    if (currentHealth < 1)
                    {
                        rlutil::locate(1,5); std::cout << "You have been defeated!! Not entirely surprising!!" << std::endl;
                        repeatFromB = false;
                        rlutil::msleep(4000);
                    }
                }
                else if (check == 2)
                {
                    std::cout << "Your new equipped weapon is " << play.weaponInventory[k].getName() << "!" << std::endl;
                    *currentWeapon = play.weaponInventory[k];
                    rlutil::msleep(2000);
                    rlutil::cls();
                    repeatFromB = false;
                    mdamage = MonsterBP(enem,play,currentHealth, currentEHealth,currentArmor);
                    updateHealth(play,enem,currentHealth,currentEHealth);
                    rlutil::msleep(200);
                    rlutil::locate(1,4);
                    loading_Six();
                    if (currentHealth < 1)
                    {
                        rlutil::locate(1,5); std::cout << "You have been defeated!! Not entirely surprising!!" << std::endl;
                        repeatFromB = false;
                        rlutil::msleep(4000);
                    }
                }
                else if (check == 3)
                {
                    std::cout << "Your new equipped armor is " << play.armorInventory[k].getName() << "!" << std::endl;
                    *currentArmor = play.armorInventory[k];
                    rlutil::msleep(2000);
                    rlutil::cls();
                    repeatFromB = false;
                    mdamage = MonsterBP(enem,play,currentHealth, currentEHealth,currentArmor);
                    updateHealth(play,enem,currentHealth,currentEHealth);
                    rlutil::msleep(200);
                    rlutil::locate(1,4);
                    loading_Six();
                    if (currentHealth < 1)
                    {
                        rlutil::locate(1,5); std::cout << "You have been defeated!! Not entirely surprising!!" << std::endl;
                        repeatFromB = false;
                        rlutil::msleep(4000);
                    }
                }
            }
            else if (choice == 3)
            {
                if (Chance_To_Run())
                {
                    rlutil::cls();
                    loading_Six();
                    std::cout << "You may be a wimp, but you sure are fast!";
                    rlutil::msleep(800);
                    repeatFromB = false;
                    repeatFromRun = false;
                }
                else
                {
                    rlutil::cls();
                    loading_Six();
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
