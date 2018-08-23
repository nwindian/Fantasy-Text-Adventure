#include "cursorSet.h"
#include <windows.h>
void cursorSet(int x, int y)
{
    static HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    static COORD CursorPosition;
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console,CursorPosition);
    return;
}
