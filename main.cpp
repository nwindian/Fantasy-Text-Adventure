#include <iostream>
#include <limits>
#include <ctime>
#include <cstdlib>
#include <vector>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <stdlib.h>
#include <memory>


HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
//#include "PlayerClass.h"
namespace playerSpace
{
    //Player Joe("Joe");
}
#include "rlutil.h"
#include "Josh/Stamina.h"
#include "Josh/Globals.h"
#include "Josh/cave_class.h"
#include "Josh/cave_constructors.h"
#include "Josh/Biome_Class.h"
#include "Josh/Prototypes.h"
#include "Josh/Biome_Constructors.h"
#include "Josh/displayMap.h"
#include "Josh/moving.h"
#include "Josh/moveOptions.h"
#include "Josh/playerView.h"
#include "Josh/cave.h"
#include "Josh/map.h"




int main()
{
	//cout << "rows " << rlutil::trows() << " columns " << rlutil::tcols();
	HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions
    //MoveWindow(window_handle, x, y, width, height, redraw_window);
    MoveWindow(console, r.left, r.top, 773, 510, TRUE);
	startMap();
    return 0;
}




