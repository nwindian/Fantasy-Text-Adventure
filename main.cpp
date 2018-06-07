#include <iostream>
#include <limits>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <windows.h>
#include <stdlib.h>
#include <memory>

using namespace std;


HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
namespace playerSpace
{
    //Player Joe("Joe");
}
#include "Josh/mapSizes"
const int MAPSIZEY = 25;
const int MAPSIZEX = (2 * MAPSIZEY);
#include "Josh/Stamina.h"
#include "Josh/cave_class.h"
#include "Josh/Biome_Class.h"
#include "Josh/Prototypes.h"
#include "Food.h"
#include "rlutil.h"





int main()
{

	startMap();
    return 0;
}




