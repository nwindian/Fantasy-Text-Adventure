#include "../include/Chance_To_Run.h"
#include <stdlib.h>
#include <time.h>
bool Chance_To_Run()
{
    int random;
    srand(time(NULL));
    random = rand() % 100 + 1;
    if (random < 51)
    {
        return true;
    }
    return false;
}
