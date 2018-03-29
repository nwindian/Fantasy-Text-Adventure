#ifndef CAVE
#define CAVE
#include "displayMap.h"



void cave(Biome& biome, int y, int x)
{
    char response = ' ';
    system ("CLS");
    cout << "        ___..-.             " << endl
         << "     ._/  __ \\_\\-._        " << endl
         << "     / .'/##\\_ -.  \\    " << endl
         << "   _/._/#####\\  \\- `\\_    " << endl
         << "  /__ /########\\_  \\._\\ " << endl
         << " /  _|###########\\_.   \\ " << endl
         << " \"'\"''\"'\"'''\" ''\"'\"''""\" " << endl;
    cout << endl << "Would you like to enter the cave? (Y)es (N)o: ";
    cin >> response;
    if (response == 'y' || response == 'Y')
    {
        int num = biome.entityMap[y][x].number;
        cout << endl << num << endl;
        biome.caves[num].display();
        displayMap(biome.map);
    }
    else
    {
        cout << endl << "Chicken!" << endl;
        cin.get();
        cin.ignore();
        displayMap(biome.map);
    }

}

#endif // CAVE
