#include "../include/cave_class.h"
#include "../include/cursorSet.h"
#include "../include/optionSelector.h"
#include "../include/clearGaps.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

Cave::Cave()
{
    depth = rand() % 5 + 6;
    theCave = new cavePiece[depth]();
}

void Cave::display()
{
   clearGaps();
   int location = 0;
   int x = 0;
   bool item;
   for (int j = 0; j <= location; ++j)
    {
        if (j != location)
        {
            cursorSet(101, 1 + j);
            std::cout << "[ ]";
        }
        else
        {
            cursorSet(101, 1 + j);
            std::cout << "[@]";
        }

    }
    cursorSet(0, 25);
    std::cout << "You enter the cave and slowly your eyes adjust. ";
    x = 48;
   for (; location < depth;)
    {
        cursorSet(x, 25);
        if (theCave[location].loot != "nothing")
        {
            std::cout << "There " << theCave[location].loot << " on the ground." << std::endl;
            std::cout << "    Pick up " << theCave[location].loot << std::endl;
            std::cout << "    Dive deeper into the cave" << std::endl;
            std::cout << "    Leave the cave" << std::endl;
            switch (optionSelector(3, 0, 26))
            {

                case 0:
                    clearGaps();
                    cursorSet(0, 25);
                    std::cout << "Loot has been put into your inventory. ";
                    theCave[location].loot = "nothing";
                    item = false;
                    x = 39;
                    //add
                    break;
                case 1:
                    clearGaps();
                    cursorSet(0, 25);
                    std::cout << "You dive deeper into the darkness. ";
                    item = true;
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
            if (item)
            {
                std::cout << std::setw(30) << std::left << "There is nothing here.";
            }
            std::cout << std::endl << "    Dive deeper into the cave" << std::endl;
            std::cout << "    Leave the cave" << std::endl;
            switch (optionSelector(2, 0, 26))
            {
                case 0:
                    clearGaps();
                    cursorSet(0, 25);
                    std::cout << "You dive deeper into the darkness. ";
                    item = true;
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

        for (int j = 0; j <= location; ++j)
        {
            if (j != location)
            {
                cursorSet(101, 1 + j);
                std::cout << "[ ]";
            }
            else
            {
                cursorSet(101, 1 + j);
                std::cout << "[@]";
            }

        }
    }
    cursorSet(0, 26);
    std::cout << "You have reached the end of the cave";
    Sleep(700);
    clearGaps();
}
