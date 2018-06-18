#include "cave_class.h"
#include "../cursorSet/cursorSet.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
using std::cout;
using std::endl;
using std::cin;

Cave::Cave()
{
    depth = rand() % 10 + 6;
    theCave = new cavePiece[depth]();
}

void Cave::display()
{
   system("CLS");
   int location = 1;
   for (int i = 0; i < depth; ++i)
    {

        char response;
        if (i == 0)
        {
           cout << "You enter the cave and slowly your eyes adjust." << endl;
           for (int i = 0; i <= location-1; ++i)
            {
                if (i != location-1)
                {
                    cursorSet(100, 1 + i);
                    //CursorPosition.X = 100;
                    //CursorPosition.Y = 1 + i;
                    //SetConsoleCursorPosition(console,CursorPosition);
                    cout << "[ ]";
                }
                else
                {
                    cursorSet(100, 1 + i);
                    //CursorPosition.X = 100;
                    //CursorPosition.Y = 1 + i;
                    //SetConsoleCursorPosition(console,CursorPosition);
                    cout << "[@]";
                }

            }
        }
        cursorSet(0, 1);
        //CursorPosition.X = 0;
        //CursorPosition.Y = 1;
        //SetConsoleCursorPosition(console,CursorPosition);
        cout << "There " << theCave[i].loot << " on the ground." << endl;
        if (theCave[i].loot != "nothing")
        {
            char input = ' ';
            cout << "Would you like to pick it up? (Y)es (N)o: ";
            input = getch();
            switch (input)
            {
                case 'Y':
                    //theCave[i].add();
                    break;
                case 'y':
                    //theCave[i].add();
                    break;
            }
        }
        cout << endl << "Would you like to continue? (Y)es (N)o: ";
        //cin.ignore();
        response = getch();

        if (response == 'y' || response == 'Y')
        {
            system("CLS");
            cout << "You dive deeper into the darkness" << endl;
            ++location;
        }
        else
        {
            system("CLS");
            cout << "You return to the entrance of the cave.\nPainfully, your eyes adjust." << endl;
            cin.ignore();
            cin.get();
            return;
        }
        for (int i = 0; i <= location-1; ++i)
        {
            if (i != location-1)
            {
                cursorSet(100, 1 + i);
                //CursorPosition.X = 100;
                //CursorPosition.Y = 1 + i;
                //SetConsoleCursorPosition(console,CursorPosition);
                cout << "[ ]";
            }
            else
            {
                cursorSet(100, 1 + i);
                //CursorPosition.X = 100;
                //CursorPosition.Y = 1 + i;
                //SetConsoleCursorPosition(console,CursorPosition);
                cout << "[@]";
            }

        }
    }
    cursorSet(0, 0);
    //CursorPosition.X = 0;
    //CursorPosition.Y = 0;
    //SetConsoleCursorPosition(console,CursorPosition);
    cout << "You have reached the end of the cave";
    cin.ignore();
    cin.get();
    system("CLS");
}
