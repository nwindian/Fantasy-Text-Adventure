#include <iostream>
#include <iomanip>
#include <limits>
#include "rlutil.h"
#include "Menu_Function.h"

int menu()
{
    int choice;
    bool repeatOne = true;
    std::cout << "1) Fight " << std::setw(5) << "2) Inventory " << std::setw(5) << "3) Attempt to Run " <<  std::endl;
    while(repeatOne == true)
    {
        if (kbhit())
        {
            std::cin.clear();
        }
        std::cin >> choice;
        if (choice  < 1 || choice > 3)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong choice doggo." << std::endl;
        }
        else
        {
            return choice;
        }
    }
}
