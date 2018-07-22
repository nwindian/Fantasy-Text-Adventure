#ifndef MOVES_CLASS_H
#define MOVES_CLASS_H


class Moves_Class
{
    public:
        Moves_Class();
        Moves_Class(std::string , int, int, std::string);
        int getDamage();
        int getEvasive();
        std::string getType();
        std::string getName();
    protected:
        int damage;
        std::string name;
        std::string type;
        int evasiveness;

    private:
};

#endif // MOVES_CLASS_H
