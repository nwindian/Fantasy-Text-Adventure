#ifndef STAMINA_H
#define STAMINA_H
//#include <memory>

class Stamina
{
    private:
        int* staminaAr;
    public:
        Stamina()
        {
            staminaAr = new int[5];
            for (int i = 0; i < 5; ++i)
            {
                staminaAr[i] = 2;
            }
        }
        Stamina(int size)
        {
            staminaAr = new int[size];
            for (int i = 0; i < size; ++i)
            {
                staminaAr[i] = 2;
            }
        }
        void decrease();
        void increase();
        void display();
        bool check();


};

#endif // STAMINA_H
