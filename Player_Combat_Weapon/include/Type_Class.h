#ifndef TYPE_CLASS_H
#define TYPE_CLASS_H
#include <iostream>


class Type_Class
{
    public:
        Type_Class();
        virtual ~Type_Class();
        char getValue();
        std::string getName();


    protected:
        char value;
        std::string name;

    private:
};

#endif // TYPE_CLASS_H
