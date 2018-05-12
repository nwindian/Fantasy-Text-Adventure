#ifndef COMBAT_EVENT_HPP_INCLUDED
#define COMBAT_EVENT_HPP_INCLUDED
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <limits>
#include "PlayerClass.h"
#include "Weapon_Class.h"
#include "Combat_Event_Prototypes.h"


using std::cout;
using std::cin;
using std::endl;

Weapon getWeapon(Player & play)
{
    cout << "Choose a weapon my loser:" << endl;
    bool repeat = false;
    int choice;
    int count = 0;
    for (int i = 0; i < play.weaponInventory.size(); ++i)
    {
        if (count == 5)
        {
            cout << endl;
            count = 0;
        }
        else
        {
            cout << i+1 << ": " << play.weaponInventory[i].getName() << " || ";
        }
    }
    cout << endl;
    while(repeat == false)
    {
        try
        {
            cin >> choice;
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
bool whosQuicker(Player & frnd, Player & enem)
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
int playerBP(Player & play, Player & enem)
{
    int damage;
    int count = 0;
    int moveChoice = 0;
    bool repeatChoice = true;
    bool repeat = true;
    int choice;
    Weapon currentWeapon = getWeapon(play);
    cout << "What would you like to do? " << endl;
    cout << "1) Fight" << std::setw(5) << "2) Inventory" << std::setw(5) << "3) Attempt to Run" << " 4) Check Environment" <<  endl;
    while(repeat == true)
    {
        cin >> choice;
        if (choice  < 1 || choice > 4)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')
            cout << "Wrong choice doggo." << endl;
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
            cout << count + 1 << ") " << play.moveList[count] << endl;
        }
        while(repeatChoice == true)
        {
            cout << "Choice: ";
            cin >> moveChoice;
            if (moveChoice < 1 || moveChoice > play.moveList.size()+1)
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Not in the range doggo." << endl;
            }
            else
            {
                repeatChoice = false;
            }
        }
        cout << play.getName() << " has used " << play.moveList[moveChoice - 1] << " to " << enem.getName() << "!" << endl;
        //Damage calculator



    }
    else if(choice == 2)
    {

    }
    else if(choice == 3)
    {

    }


}
//Main function for Combat.
void combat(Player & play,Player & enem)
{
    int playerHealth = play.getHealth();
    int enemyHealth = enem.getHealth();
    //health after the battle phase.
    int newPlayerHealth;
    int newEnemyHealth;
    cout << "You have entered combat with " << enem.getName() << "!!" << endl;
    //loop through battle until someone has 0 health (dies)
    while (play.getHealth() > 0 && enem.getHealth() > 0)
    {
        if (whosQuicker(play, enem))
        {

        }
    }
}


#endif // COMBAT_EVENT_HPP_INCLUDED
