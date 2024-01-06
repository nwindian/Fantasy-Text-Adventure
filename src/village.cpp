#include "../include/village.h"
#include "../include/cursorSet.h"
#include "../include/optionSelector.h"
#include "../include/clearGaps.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
using std::cout;
using std::setw;
using std::endl;

void village()
{
    clearGaps();
    cursorSet(0, 25);
    cout << "Would you like to enter the village?" << endl;
    cout << "    Yes" << endl;
    cout << "    No" << endl;
    while (true)
    {
        switch (optionSelector(2, 0, 26))
        {
            case 0:
                {
                    cursorSet(0, 25);
                    cout << setw(50) << " ";
                    cursorSet(0, 25);
                    cout << "Where would you like to go?";
                    cursorSet(0, 26);
                    cout << "    Weapon and Armor Smith\n"
                         << "    Food Shop\n"
                         << "    Scroll shop\n"
                         << "    Explore\n"
                         << "    Leave";
                    int pick = optionSelector(5, 0, 26);
                    for (int y = 25; y < 31; ++y)
                    {
                        cursorSet(0, y);
                        cout << setw(30) << " ";
                    }
                    cout << pick;
                    switch (pick)
                    {
                        case 0:
                            break;
                        case 1:
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            clearGaps();
                            return;
                    }
                    break;
                }
            case 1:
                clearGaps();
                return;
                break;
        }
    }
}
