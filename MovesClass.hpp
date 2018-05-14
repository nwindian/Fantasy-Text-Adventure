#ifndef MOVESCLASS_HPP_INCLUDED
#define MOVESCLASS_HPP_INCLUDED
#include <iostream>

class Moves
{
    private:
        int damage;
        std::string name;
        char type;
        int evasiveness;
    public:
        Moves(std::string , int, int);
        int getDamage()
        {
            return damage;
        }
        int getEvasive()
        {
            return evasiveness;
        }
};

Moves::Moves(std::string nameO, int damageO, int evasivenesss)
{
    damage = damageO;
    name = nameO;
    evasiveness = evasivenesss;
}
#endif // MOVESCLASS_HPP_INCLUDED
