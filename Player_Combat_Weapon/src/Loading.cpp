#include <iostream>
#include "Loading.h"
#include "rlutil.h"

void loading_Six()
{
    for (int i = 0;i < 3; ++i)
    {
        std::cout << ". ";
        rlutil::msleep(600);
    }
}
