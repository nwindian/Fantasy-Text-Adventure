#ifndef UPPER_BOUND_H_INCLUDED
#define UPPER_BOUND_H_INCLUDED
#include <vector>
template <class T>
int Upper_bound(std::vector<T>);

template <class T>
int Upper_bound(std::vector<T> vec)
{
    return vec.size();
}


#endif // UPPER_BOUND_H_INCLUDED
