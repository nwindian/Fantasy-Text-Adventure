#include <iostream>
#include <conio.h>
#include <iomanip>
#include <limits>
#include <windows.h>
#include "Upper_Bound.h"
#include "Player_Class.h"
#include "Chance_Calc_Interface.h"
#include "Damage_Calculator.h"
#include "Chance_Calc_Interface.h"
#include "Weapon_Class.h"
#include "rlutil.h"




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
    return play.weaponInventory[choice - 1];
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
    bool repeat = true;
    int x = 23;
    int y = 7;
    unsigned int moveChoice;
    unsigned int choice;
    int upBound;
    rlutil::cls();
    Weapon_Class currentWeapon = getWeapon(play);
    rlutil::setColor(2);
    std::cout << "What would you like to do? " << std::endl;
    do
    {
        unsigned int count = 0;
        bool repeatChoice = true;
        //color
        rlutil::setColor(6);
        std::cout << "1) Fight " << std::setw(5) << "2) Inventory " << std::setw(5) << "3) Attempt to Run " << " 4) Check Environment" <<  std::endl;
        while(repeat == true)
        {
            if (kbhit())
            {
                std::cin.clear();
            }
            //choice = rlutil::getkey();
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
            rlutil::locate(30,7); std::cout << "Press space to go back" << std::endl;
            //rlutil::locate(1,7);
            while(count < play.moveList.size())
            {
                std::cout << count + 1 << ") " << play.moveList[count].getName() << std::endl << std::endl;
                ++count;
            }
            while(repeatChoice == true)
            {
                upBound = Upper_bound(play.moveList);
                int l = upBound * 2;
                while (true) {
               // rlutil::locate(1,4); std::cout << "Turn count: " << cnt;
                    rlutil::locate(x,y);
                    rlutil::hidecursor();
                    std::cout << " <--";
                    if (!kbhit()) {
                        char k = getch(); // Get character
                        rlutil::locate(x,y); std::cout << "     "; // Erase player
                        if (k == 'w')
                        {
                            if (y == 7)
                            {
                                y = y + l - 2;
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
                                y = 7;
                            }
                            else
                            {
                                y = y + 2;
                            }

                        }
                        else if (k == ' ')
                        {
                            //////////FIGURE OUT HOW TO DO DIS
                            rlutil::cls();
                            repeatChoice = false;
                            repeat = true;
                            break;
                        }
                       // rlutil::locate(x,y); std::cout << '@'; // Output player
                    }
                }
            if (repeat == true)
            {
                break;
            }
            //Check if move hits
            else if (!chance(play, play.moveList[moveChoice-1]))
            {
                std::cout << play.getName() << " has missed!" << std::endl;
                return 0;
            }
            std::cout << play.getName() << " has used " << play.moveList[moveChoice - 1].getName() << " to " << enem.getName() << "!" << std::endl;
            //Damage calculator
            return dmg_calc(play, enem, currentWeapon);
        }
        }
        else if(choice == 2)
        {

        }
        else if(choice == 3)
        {

        }
        else if (choice == 4)
        {

        }
    }
    while(repeat == true);
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
