#include "../include/mapSizes.h"
#include "../include/cursorSet.h"
#include "../include/mapSizes.h"
#include <iostream>
#include <windows.h>
void displayMap(char** map, int color)
{
    cursorSet(0, 0);
    switch(color)
    {
        case 2:
            SetConsoleTitle("The Forest");
            break;
        case 11:
            SetConsoleTitle("The Tundra");
            break;
        case 14:
            SetConsoleTitle("The Desert");
            break;
        case 8:
            SetConsoleTitle("The Mountains");
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
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return;
}
