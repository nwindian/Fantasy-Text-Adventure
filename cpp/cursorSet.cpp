void cursorSet(int num1, int num2)
{
    CursorPosition.X = num1;
    CursorPosition.Y = num2;
    SetConsoleCursorPosition(console,CursorPosition);
    return;
}
