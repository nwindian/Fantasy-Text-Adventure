#ifndef ARMOR_CLASS_H
#define ARMOR_CLASS_H
#include <iostream>
#include <string>

class Armor_Class
{
    public:
        Armor_Class();
        Armor_Class(int, std::string, std::string);
        int getArmor();
        void setArmor(int);
        const std::string getType();
        const std::string getName();

    protected:
        int armor;
        std::string name;
        std::string type;

    private:
};

#endif // ARMOR_CLASS_H
