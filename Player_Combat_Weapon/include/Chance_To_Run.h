#ifndef CHANCE_TO_RUN_H_INCLUDED
#define CHANCE_TO_RUN_H_INCLUDED
#include <stdlib.h>
#include <time.h>
bool Chance_To_Run();
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



#endif // CHANCE_TO_RUN_H_INCLUDED
