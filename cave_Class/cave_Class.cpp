#include "cave_class.h"
#include "../cursorSet/cursorSet.h"
#include "../optionSelector/optionSelector.h"
#include "../clearGaps/clearGaps.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

Cave::Cave()
{
    depth = rand() % 10 + 6;
    theCave = new cavePiece[depth]();
}

void Cave::display()
{
   clearGaps();
   int location = 1;
   int x = 0;
   for (int i = 0; i < depth; ++i)
    {
        if (i == 0)
        {

           for (int i = 0; i <= location-1; ++i)
            {
                if (i != location-1)
                {
                    cursorSet(101, 1 + i);
                    std::cout << "[ ]";
                }
                else
                {
                    cursorSet(101, 1 + i);
                    std::cout << "[@]";
                }

            }
            cursorSet(0, 25);
            std::cout << "You enter the cave and slowly your eyes adjust. ";
            x =48;
        }
        cursorSet(x, 25);
        if (theCave[i].loot != "nothing")
        {
            std::cout << "There " << theCave[i].loot << " on the ground." << std::endl;
            std::cout << "    Pick up " << theCave[i].loot << std::endl;
            std::cout << "    Dive deeper into the cave" << std::endl;
            std::cout << "    Leave the cave" << std::endl;
            switch (optionSelector(3, 0, 26))
            {

                case 0:
                    clearGaps();
                    cursorSet(0, 25);
                    std::cout << "Loot has been put into your inventory. ";
                    x =39;
                    //add
                    break;
                case 1:
                    clearGaps();
                    cursorSet(0, 25);
                    std::cout << "You dive deeper into the darkness. ";
                    x = 35;
                    ++location;
                    break;
                case 2:
                    clearGaps();
                    cursorSet(0, 25);
                    std::cout << "You return to the entrance of the cave. Painfully, your eyes adjust." << std::endl;
                    Sleep(500);
                    return;

            }
        }
        else
        {
            std::cout << std::setw(30) << std::left << "There is nothing here." << std::endl;
            std::cout << "    Dive deeper into the cave" << std::endl;
            std::cout << "    Leave the cave" << std::endl;
            switch (optionSelector(2, 0, 26))
            {
                case 0:
                    clearGaps();
                    cursorSet(0, 25);
                    std::cout << "You dive deeper into the darkness. ";
                    x = 35;
                    ++location;
                    break;
                case 1:
                    clearGaps();
                    cursorSet(0, 25);
                    std::cout << "You return to the entrance of the cave.\nPainfully, your eyes adjust." << std::endl;
                    Sleep(700);
                    return;
            }
        }

        for (int i = 0; i <= location-1; ++i)
        {
            if (i != location-1)
            {
                cursorSet(101, 1 + i);
                std::cout << "[ ]";
            }
            else
            {
                cursorSet(101, 1 + i);
                std::cout << "[@]";
            }

        }
    }
    cursorSet(0, 26);
    std::cout << "You have reached the end of the cave";
    Sleep(700);
    clearGaps();
}
