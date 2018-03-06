#ifndef CAVE
#define CAVE

class cavePiece
{
    private:
        int heat = 0;
        string message = "You enter the cave and slowly your eyes adjust.";
        bool gold = false;
        bool weapon = false;
        bool food = false;
        bool waterSkin = false;
        bool scroll = false;
    public:
        cavePiece();
        cavePiece(int, string);
        pieceDisplay();



};

void cave(Biome& biome, int y, int x)
{
    char response = ' ';
    cout << string(100, '\n');
    cout << "        ___..-.             " << endl
         << "     ._/  __ \\_\\-._        " << endl
         << "     / .'/##\\_ -.  \\    " << endl
         << "   _/._/#####\\  \\- `\\_    " << endl
         << "  /__ /########\\_  \\._\\ " << endl
         << " /  _|###########\\_.   \\ " << endl
         << " \"'\"''\"'\"'''\" ''\"'\"''""\" " << endl;
    cout << endl << "Would you like to enter the cave? (Y)es (N)o: ";
    cin >> response;
    if (response == 'y' || response == 'Y')
        cout << endl << "cave" << endl;
    else
    {
        cout << endl << "Chicken!" << endl;
    }
    cin.ignore();
    cin.get();
}

#endif // CAVE
