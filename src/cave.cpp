#include "../include/cave.h"
#include "../include/Biome_Class.h"
#include "../include/displayMap.h"
#include "../include/cursorSet.h"
#include "../include/optionSelector.h"
#include "../include/clearGaps.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

void cave(Biome& biome, int y, int x)
{
    clearGaps();
    cursorSet(0, 25);
    std::cout << "Would you like to enter the cave?" << std::endl;
    std::cout << "    Yes" << std::endl;
    std::cout << "    No";

    while (true)
    {
        switch(optionSelector(2, 0, 26))
        {
            case 0:
                {
                    int num = biome.entityMap[y][x].number;
                    biome.caves[num].display();
                    displayMap(biome.map, biome.getColor());
                    return;
                }
            case 1:
                clearGaps();
                cursorSet(0, 25);
                std::cout << std::endl << "Chicken!" << std::endl;
                Sleep(500);
                displayMap(biome.map, biome.getColor());
                return;
        }
    }
}
