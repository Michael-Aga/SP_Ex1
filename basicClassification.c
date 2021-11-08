#include <math.h>
#include <stdio.h>
#include "NumClass.h"

int fact(int n)
{
    return (n == 0) || (n == 1) ? 1 : n * fact(n - 1);
}

int isStrong(int N)
{
    int Num = N, rem, result = 0;
    while (Num != 0)
    {
        rem = Num % 10;
        result += fact(rem);
        Num = Num / 10;
    }
    if (result == N)
        return 1;
    return 0;
}

int isPrime(int n)
{
    if(n == 1)
    {
        return 1;
    }
    int i, value, value2, count = 0;

    value = n;
    value2 = ceil((int)sqrt(n));
    for (i = 2; i <= value2; i++)
    {
        if (value % i == 0)
            count = 1;
    }
    if ((count == 0 && value != 1) || value == 2 || value == 3)
        return 1;
    return 0;
}