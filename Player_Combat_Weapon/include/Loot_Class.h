#ifndef LOOT_CLASS_H
#define LOOT_CLASS_H


class Loot_Class
{
    public:
        Loot_Class();
        virtual ~Loot_Class();
        virtual int getChoiceForInventory();
        virtual void showInventory(Loot_Class );

    protected:

    private:
};

#endif // LOOT_CLASS_H
