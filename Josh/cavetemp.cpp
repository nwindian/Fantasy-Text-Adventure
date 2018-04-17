#include <iostream>
#include <limits>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;
class cave
{
    private:
        int Size = 0;
        struct cavePiece
        {
            string msg = "maybe its working this time";
        };
        vector<cavePiece> caveVec;
    public:
        cave();
        void displayCave();
};

int main()
{
    srand(time(0));
    cave test;
    //cout << test.test();
    test.displayCave();
}

cave::cave()
{


    int caveSize[] = {3, 8, 10};
    Size = caveSize[rand() % 3];
    for (int i = 0; i < Size; ++i)
    {
        caveVec.push_back(cavePiece());
    }
}

void cave::displayCave()
{
    for (int i = 0; i < Size; ++i)
    {
        cout << caveVec[i].msg << endl;
    }
}
