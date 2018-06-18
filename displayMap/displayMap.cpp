#include "mapSizes.h"
#include "../cursorSet/cursorSet.h"
#include "../rlutil.h"
#include "../Josh/mapSizes.h"
#include <iostream>
using std::cout;
using std::endl;
void displayMap(char map[][MAPSIZEX], int color)
{
    cursorSet(0, 0);
    switch(color)
    {
        case 2:
            rlutil::setConsoleTitle("Forest");
            break;
        case 11:
            rlutil::setConsoleTitle("Tundra");
            break;
        case 14:
            rlutil::setConsoleTitle("Desert");
            break;
        case 8:
            rlutil::setConsoleTitle("Mountain");
            break;
    }
    for (int i = 0; i < MAPSIZEY ; ++i)
    {
        for (int j = 0;  j < MAPSIZEX; ++j)
        {
            if (map[i][j] == '\'')
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    return;
}
