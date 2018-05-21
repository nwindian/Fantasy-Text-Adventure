#include <iostream>
#include <conio.h>
#include <iomanip>
#include <limits>
#include <windows.h>
#include "Player_Class.h"
#include "Chance_Calc_Interface.h"
#include "Damage_Calculator.h"
#include "Chance_Calc_Interface.h"
#include "Weapon_Class.h"



Weapon_Class getWeapon(Player_Class & play)
{
    std::cout << "Choose a weapon my Player:" << std::endl;
    bool repeat = false;
    int choice;
    int count = 0;
    for (int i = 0; i < play.weaponInventory.size(); ++i)
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
        try
        {
            std::cin >> choice;
            throw choice;
        }
        catch(int choiceof)
        {
            if(choiceof < 0 || choiceof > play.weaponInventory.size())
            {
                repeat = false;
            }
            else
            {
                repeat = true;
            }
        }
    }
    return play.weaponInventory[choice -1];
}
//To check who is faster
bool whosQuicker(Player_Class & frnd, Player_Class & enem)
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
//Players battle phase
int playerBP(Player_Class & play, Player_Class & enem)
{
    int count = 0;
    int moveChoice = 0;
    bool repeatChoice = true;
    bool repeat = true;
    int choice;
    Weapon_Class currentWeapon = getWeapon(play);
    std::cout << "What would you like to do? " << std::endl;
    std::cout << "1) Fight" << std::setw(5) << "2) Inventory" << std::setw(5) << "3) Attempt to Run" << " 4) Check Environment" <<  std::endl;
    while(repeat == true)
    {
        std::cin >> choice;
        if (choice  < 1 || choice > 4)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong choice doggo." << std::endl;
        }
        else
        {
            repeat = false;
        }
    }
    if (choice == 1)
    {
        while(count < play.moveList.size())
        {
            std::cout << count + 1 << ") " << play.moveList[count].getName() << std::endl;
        }
        while(repeatChoice == true)
        {
            std::cout << "Choice: ";
            std::cin >> moveChoice;
            if (moveChoice < 1 || moveChoice > play.moveList.size()+1)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Not in the range doggo." << std::endl;
            }
            else
            {
                repeatChoice = false;
            }
        }
        //Check if move hits
        if (!chance(play, play.moveList[moveChoice-1]))
        {
            std::cout << play.getName() << " has missed!" << std::endl;
            return 0;
        }
        std::cout << play.getName() << " has used " << play.moveList[moveChoice - 1].getName() << " to " << enem.getName() << "!" << std::endl;
        //Damage calculator
        return dmg_calc(play, enem, currentWeapon);
    }
    else if(choice == 2)
    {

    }
    else if(choice == 3)
    {

    }


}
//Main function for Combat.
void combat(Player_Class & play,Player_Class & enem)
{
    int damage;
    int playerHealth = play.getHealth();
    int enemyHealth = enem.getHealth();
    //health after the battle phase.
    int newPlayerHealth;
    int newEnemyHealth;
    std::cout << "You have entered combat with " << enem.getName() << "!!" << std::endl;
    //loop through battle until someone has 0 health (dies)
    while (play.getHealth() > 0 && enem.getHealth() > 0)
    {
        if (whosQuicker(play, enem))
        {
            damage = playerBP(play, enem);
        }
    }
}
