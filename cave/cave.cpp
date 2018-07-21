#include "cave.h"
#include "../Biome_Class/Biome_Class.h"
#include "../displayMap/displayMap.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

void cave(Biome& biome, int y, int x)
{
    system ("CLS");
    std::cout << "Would you like to enter the cave? (Y)es (N)o";
    while (true)
    {
        switch(getch())
        {
            case 'y':
                {
                    int num = biome.entityMap[y][x].number;
                    biome.caves[num].display();
                    displayMap(biome.map, biome.getColor());
                    return;
                }
            case 'Y':
                 {
                    int num = biome.entityMap[y][x].number;
                    biome.caves[num].display();
                    displayMap(biome.map, biome.getColor());
                    return;
                }
            case 'n':
                std::cout << std::endl << "Chicken!" << std::endl;
                Sleep(500);
                displayMap(biome.map, biome.getColor());
                return;
                return;
            case 'N':
                std::cout << std::endl << "Chicken!" << std::endl;
                Sleep(500);
                displayMap(biome.map, biome.getColor());
                return;
        }
    }
}
