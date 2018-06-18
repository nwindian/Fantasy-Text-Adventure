#include "cursorSet.h"
#include <windows.h>
void cursorSet(int num1, int num2)
{
    static HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    static COORD CursorPosition;
    CursorPosition.X = num1;
    CursorPosition.Y = num2;
    SetConsoleCursorPosition(console,CursorPosition);
    return;
}
