void village()
{
    cursorSet(0, 27);
    cout << setw(50) << " ";
    cursorSet(0, 28);
    cout << setw(50) << " ";
    cursorSet(0, 25);
    cout << "Would you like to enter the village? (Y)es (N)o";
    do
    {
        char responce = getch();
        if (responce == 'y')
        {
            cursorSet(0, 25);
            cout << setw(50) << " ";
            cursorSet(0, 25);
            cout << "Where would you like to go?";
            cursorSet(0, 26);
            cout << "(1) Weapon and Armor Smith\n"
                 << "(2) Food Shop\n"
                 << "(3) Scroll shop\n"
                 << "(4) Explore\n"
                 << "(5) Leave";
                 cin.get();
                 return;

        }
        else if (responce == 'n')
        {
            cursorSet(0, 26);
            cout << setw(30) << left << "Very well";
            cin.get();
            return;
        }
    } while (true);
}
