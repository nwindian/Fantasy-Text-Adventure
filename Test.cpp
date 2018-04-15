#include <iostream>
#include "PlayerClass.h"
#include "MovesClass.hpp"
#include "Status_Namespace.h"
#include "Weapon_Class.h"
#include "Weapon_objects.hpp"

using namespace std;

int main()
{
    Player Joe("Joe");
    Joe.LevelUP(Joe);
    return 0;
}
