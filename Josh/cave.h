#ifndef CAVE
#define CAVE
#include "displayMap.h"



void cave(Biome& biome, int y, int x)
{
    char response = ' ';
    system ("CLS");
    cout << "Would you like to enter the cave? (Y)es (N)o: ";
    cin >> response;
    if (response == 'y' || response == 'Y')
    {
        int num = biome.entityMap[y][x].number;
        biome.caves[num].display();
        displayMap(biome.map);
    }
    else
    {
        cout << "Chicken!" << endl;
        cin.get();
        cin.ignore();
        displayMap(biome.map);
    }

}

#endif // CAVE
