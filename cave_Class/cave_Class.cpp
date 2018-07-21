#include "cave_class.h"
#include "../cursorSet/cursorSet.h"
#include "../optionSelector/optionSelector.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
using std::cout;
using std::endl;
using std::cin;

Cave::Cave()
{
    depth = rand() % 10 + 6;
    theCave = new cavePiece[depth]();
}

void Cave::display()
{
   system("CLS");
   int location = 1;
   for (int i = 0; i < depth; ++i)
    {
        if (i == 0)
        {
           std::cout << "You enter the cave and slowly your eyes adjust." << std::endl;
           for (int i = 0; i <= location-1; ++i)
            {
                if (i != location-1)
                {
                    cursorSet(100, 1 + i);
                    std::cout << "[ ]";
                }
                else
                {
                    cursorSet(100, 1 + i);
                    std::cout << "[@]";
                }

            }
        }
        cursorSet(0, 1);
        if (theCave[i].loot != "nothing")
        {
            std::cout << "There " << theCave[i].loot << " on the ground." << std::endl;
            std::cout << "    Pick up " << theCave[i].loot << std::endl;
            std::cout << "    Dive deeper into the cave" << std::endl;
            std::cout << "    Leave the cave" << std::endl;
            switch (optionSelector(3, 0, 2))
            {
                case 0:
                    system("CLS");
                    cursorSet(0, 0);
                    std::cout << "Loot has been put into your inventory" << std::endl;
                    //add
                    break;
                case 1:
                    system("CLS");
                    std::cout << "You dive deeper into the darkness" << std::endl;
                    ++location;
                    break;
                case 2:
                    system("CLS");
                    std::cout << "You return to the entrance of the cave.\nPainfully, your eyes adjust." << std::endl;
                    Sleep(500);
                    return;

            }
        }
        else
        {
            std::cout << std::setw(30) << std::left << "There is nothing here" << std::endl;
            std::cout << "    Dive deeper into the cave" << std::endl;
            std::cout << "    Leave the cave" << std::endl;
            switch (optionSelector(2, 0, 2))
            {
                case 0:
                    system("CLS");
                    std::cout << "You dive deeper into the darkness" << std::endl;
                    ++location;
                    break;
                case 1:
                    system("CLS");
                    std::cout << "You return to the entrance of the cave.\nPainfully, your eyes adjust." << std::endl;
                    Sleep(500);
                    return;
            }
        }

        for (int i = 0; i <= location-1; ++i)
        {
            if (i != location-1)
            {
                cursorSet(100, 1 + i);
                std::cout << "[ ]";
            }
            else
            {
                cursorSet(100, 1 + i);
                std::cout << "[@]";
            }

        }
    }
    cursorSet(0, 0);
    std::cout << "You have reached the end of the cave";
    Sleep(500);
    system("CLS");
}
