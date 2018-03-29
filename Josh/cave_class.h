#ifndef CAVE_CLASS
#define CAVE_CLASS

class Cave
{
    private:
        int depth = 0;
        struct cavePiece
        {
            int heat = 0;
            string message = "There is nothing here.";
            bool gold = false;
            bool weapon = false;
            bool food = false;
            bool waterSkin = false;
            bool scroll = false;
        };
        vector<cavePiece> caveVec;
    public:
        Cave();
        void display();
};

#endif // CAVE_CLASS
