#include <iostream>
#include "PlayerClass.h"
#include "MovesClass.hpp"
#include "Status_Namespace.h"
#include "Weapon_Class.h"
#include "Weapon_objects.hpp"
#include <typeinfo>
#include <memory>
#include <type_traits>
#include <cstdlib>

using namespace std;
int main()
{
    int j;
    Player Joe("Joe");
    Joe.LevelUP(Joe);
    return 0;
}
