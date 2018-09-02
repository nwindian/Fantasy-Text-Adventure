#include "cave.h"
#include "../Biome_Class/Biome_Class.h"
#include "../displayMap/displayMap.h"
#include "../cursorSet/cursorSet.h"
#include "../optionSelector/optionSelector.h"
#include "../clearGaps/clearGaps.h"
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
                    int num = biome.entityMap[y][x].caveNumber;
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
