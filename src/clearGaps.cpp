#include "../include/clearGaps.h"
#include "../include/cursorSet.h"
#include <iostream>
#include <iomanip>

void clearGaps()
{
    for (int i = 0; i < 25; ++i)
    {
        cursorSet(100, i);
        std::cout << std::setw(20) << " ";
    }
    for (int i = 0; i < 4; ++i)
    {
        cursorSet(0, 25 + i);
        std::cout << std::setw(120) << " ";
    }
}
