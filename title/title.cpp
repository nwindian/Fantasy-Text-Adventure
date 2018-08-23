#include "title.h"
#include "../cursorSet/cursorSet.h"
#include "../player/player.h"
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
                cursorSet(20, 10);
                std::cout << "    _   __                                                  __                   ";
                cursorSet(20, 11);
                std::cout << "   / | / /___ _____ ___  ___     __  ______  __  _______   / /_  ___  _________  ";
                cursorSet(20, 12);
                std::cout << "  /  |/ / __ `/ __ `__ \\/ _ \\   / / / / __ \\/ / / / ___/  / __ \\/ _ \\/ ___/ __ \\ ";
                cursorSet(20, 13);
                std::cout << " / /|  / /_/ / / / / / /  __/  / /_/ / /_/ / /_/ / /     / / / /  __/ /  / /_/ / ";
                cursorSet(20, 14);
                std::cout << "/_/ |_/\\__,_/_/ /_/ /_/\\___/   \\__, /\\____/\\__,_/_/     /_/ /_/\\___/_/   \\____/  ";
                cursorSet(20, 15);
                std::cout << "                              /____/                                             ";
                cursorSet(60, 17);
                getline(std::cin, name);
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
                cursorSet(20, 10);
                std::string name;
                cursorSet(20, 10);
                std::cout << "    _   __                                                  __                   ";
                cursorSet(20, 11);
                std::cout << "   / | / /___ _____ ___  ___     __  ______  __  _______   / /_  ___  _________  ";
                cursorSet(20, 12);
                std::cout << "  /  |/ / __ `/ __ `__ \\/ _ \\   / / / / __ \\/ / / / ___/  / __ \\/ _ \\/ ___/ __ \\ ";
                cursorSet(20, 13);
                std::cout << " / /|  / /_/ / / / / / /  __/  / /_/ / /_/ / /_/ / /     / / / /  __/ /  / /_/ / ";
                cursorSet(20, 14);
                std::cout << "/_/ |_/\\__,_/_/ /_/ /_/\\___/   \\__, /\\____/\\__,_/_/     /_/ /_/\\___/_/   \\____/  ";
                cursorSet(20, 15);
                std::cout << "                              /____/                                             ";
                cursorSet(60, 17);
                std::cin >> name;
                player::players.setName(name);
                return;
            }
        }
    }
}
