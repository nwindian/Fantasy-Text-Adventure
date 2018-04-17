#ifndef CAVE_CONSTRUCTORS
#define CAVE_CONSTRUCTORS
#include <conio.h>

Cave::Cave()
{


    depth = rand() % 10 + 6;
    theCave = new cavePiece[depth]();
    for (int i = 0; i < depth; ++i)
    {
        //theCave[i] = new cavePiece();
    }
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
                    CursorPosition.X = 100;
                    CursorPosition.Y = 1 + i;
                    SetConsoleCursorPosition(console,CursorPosition);
                    cout << "[ ]";
                }
                else
                {
                    CursorPosition.X = 100;
                    CursorPosition.Y = 1 + i;
                    SetConsoleCursorPosition(console,CursorPosition);
                    cout << "[@]";
                }

            }
        }
        CursorPosition.X = 0;
        CursorPosition.Y = 1;
        SetConsoleCursorPosition(console,CursorPosition);
        cout << "There is " << theCave[i].loot << " on the ground." << endl;
        if (theCave[i].loot != "nothing")
        {
            cout << "Would you like to pick it up? (Y)es (N)o: ";
            getch();
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
                CursorPosition.X = 100;
                CursorPosition.Y = 1 + i;
                SetConsoleCursorPosition(console,CursorPosition);
                cout << "[ ]";
            }
            else
            {
                CursorPosition.X = 100;
                CursorPosition.Y = 1 + i;
                SetConsoleCursorPosition(console,CursorPosition);
                cout << "[@]";
            }

        }
    }
    CursorPosition.X = 0;
    CursorPosition.Y = 0;
    SetConsoleCursorPosition(console,CursorPosition);
    cout << "You have reached the end of the cave";
    cin.ignore();
    cin.get();
    system("CLS");
}


#endif // CAVE_CONSTRUCTORS
