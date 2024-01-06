#include "../include/title.h"
#include "../include/cursorSet.h"
#include "../include/player.h"
#include <iostream>
#include <windows.h>
#include <conio.h>

void title()
{
    SetConsoleTitle("Achimel");
    cursorSet(25, 10);
    std::cout << " ______     ______     __  __     __     __    __     ______     __        ";
    cursorSet(25, 11);
    std::cout << "/\\  __ \\   /\\  ___\\   /\\ \\_\\ \\   /\\ \\   /\\ \"-./  \\   /\\  ___\\   /\\ \\       ";
    cursorSet(25, 12);
    std::cout << "\\ \\  __ \\  \\ \\ \\____  \\ \\  __ \\  \\ \\ \\  \\ \\ \\-./\\ \\  \\ \\  __\\   \\ \\ \\____  ";
    cursorSet(25, 13);
    std::cout << " \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_\\  \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\ \\_____\\ ";
    cursorSet(25, 14);
    std::cout << "  \\/_/\\/_/   \\/_____/   \\/_/\\/_/   \\/_/   \\/_/  \\/_/   \\/_____/   \\/_____/ ";
    cursorSet(60, 17);
    char option = ' ';
    while (option != 13)
    {
        cursorSet(50, 17);
        std::cout << "Press Enter to Start";
        Sleep(600);
        if (kbhit())
        {
            if (getch() == 13)
            {
                system("CLS");
                std::string name;
                std::cout << "Enter player name: ";
                std::cin >> name;
                player::players.setName(name);
                return;
            }
        }
        cursorSet(50, 17);
        std::cout << "                    ";
        Sleep(300);
        if (kbhit())
        {
            if (getch() == 13)
            {
                system("CLS");
                std::string name;
                std::cout << "Enter player name: ";
                std::cin >> name;
                player::players.setName(name);
                return;
            }
        }
    }
}
