#ifndef WEAPON_CLASS_H
#define WEAPON_CLASS_H
#include <iostream>
#include <string>
#include "Loot_Class.h"


class Weapon_Class : public Loot_Class
{
    public:
        Weapon_Class();
        Weapon_Class(int ,char, std::string);
        Weapon_Class(const Weapon_Class& other);
        //int setDmg(Weapon_Class &, char);
        bool getSword() const;
        bool getAxe() const;
        int getDmg() const;
        char getType() const;
        std::string getName() const;
        void setDmg(int);
        void setType(char);
        void setName(std::string);

    protected:
        int dmg;
        char type;
        std::string name;

    private:
};

#endif // WEAPON_CLASS_H
