#ifndef CAVE_CONSTRUCTORS
#define CAVE_CONSTRUCTORS

Cave::Cave()
{


    int caveSize[] = {3, 8, 9};
    depth = caveSize[rand() % 3];
    for (int i = 0; i < depth; ++i)
    {
        caveVec.push_back(cavePiece());
    }
}

void Cave::display()
{
    for (int i = 0; i < depth; ++i)
    {
        char response;
        if (i == 0)
        {
           cout << "You enter the cave and slowly your eyes adjust.";
        }
        cout << endl << caveVec[i].message << endl
             << "Would you like to continue? (Y)es (N)o: ";
        cin.ignore();
        cin.get(response);
        if (response == 'y' || response == 'Y')
        {
            cout << endl << "You dive deeper into the darkness" << endl;
        }
        else
        {
            cout << endl << "You return to the entrance of the cave.\nPainfully, your eyes adjust." << endl;
            cin.ignore();
            cin.get();
            return;
        }
    }
}


#endif // CAVE_CONSTRUCTORS
