#ifndef MOVESCLASS_HPP_INCLUDED
#define MOVESCLASS_HPP_INCLUDED
#include <iostream>

class Moves
{
    private:
        int damage;
        std::string name;
        char type;
    public:
        Moves(std::string , int );
        int getDamage()
        {
            return damage;
        }
};

Moves::Moves(std::string nameO, int damageO)
{
    damage = damageO;
    name = nameO;
}
#endif // MOVESCLASS_HPP_INCLUDED
