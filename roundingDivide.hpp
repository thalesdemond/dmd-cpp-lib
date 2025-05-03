#pragma once
template<typename T>
T roundingDivide(T n, T d)
{
    if(!d) return (0);
    if((n < 0) == (d < 0)) //resulti is positive
    {
        printf("1 : ");
        return ((n + d/2)/ d);
    }
    else
    {
        printf("2 : ");
        return ((n - d / 2)/ d);
    }
}
