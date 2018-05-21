#ifndef ARMOR_CLASS_H
#define ARMOR_CLASS_H

class Armor_Class
{
    public:
        Armor_Class();
        Armor_Class(int, std::string, char);

    protected:
        private:
        int armor;
        std::string name;
        char resistance;

    private:
};

#endif // ARMOR_CLASS_H
