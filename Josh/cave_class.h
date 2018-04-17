#ifndef CAVE_CLASS
#define CAVE_CLASS

class Cave
{
    private:
        int depth = 0;
        struct cavePiece
        {
            int heat = 0;
            string message = " ";
            bool gold = false;
            bool weapon = false;
            bool food = false;
            //bool waterSkin = false;
            bool scroll = false;
            bool armor = false;
            cavePiece()
            {
                int num = rand() % 100;
                if (num < 50)
                {
                    if (num > 29)
                    {
                        food = true;
                    }
                    else if (num > 14)
                    {
                        gold = true;
                    }
                    else if (num > 9)
                    {
                        weapon = true;
                    }
                    else if (num > 4)
                    {
                        scroll = true;
                    }
                    else
                    {
                        armor = true;
                    }
                }
            }
            cavePiece(string& msg) : message(msg)
            {
                int num = rand() % 100;
                if (num < 50)
                {
                    if (num > 29)
                    {
                        food = true;
                    }
                    else if (num > 14)
                    {
                        gold = true;
                    }
                    else if (num > 9)
                    {
                        weapon = true;
                    }
                    else if (num > 4)
                    {
                        scroll = true;
                    }
                    else
                    {
                        armor = true;
                    }
                }
            }
        };
        cavePiece* theCave;
    public:
        Cave();
        void display();
};

#endif // CAVE_CLASS
