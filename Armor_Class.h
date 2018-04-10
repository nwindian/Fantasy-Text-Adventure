#ifndef ARMOR_CLASS_H_INCLUDED
#define ARMOR_CLASS_H_INCLUDED
#include <iostream>
class Armor
{
private:
    int armor;
    std::string name;
    char resistance;
public:
    Armor()
    {
        armor = 0;
        name = " ";
        resistance = 'N';
    }
    Armor(int arm, std::string nameof, char resist)
    {
        armor = arm;
        name = nameof;
        resistance = resist;
    }
};


#endif // ARMOR_CLASS_H_INCLUDED
