#pragma once

template<typename T, unsigned long int S>
T mean(const T (&a)[S])
{
    T s = 0;
    for(auto item : a)
    {
        s += item;
    }
    return (s / S);
}
