#include <math.h>
#include <stdio.h>
#include "NumClass.h"

int isArmstrong(int n)
{
    int count = 0, num = n, check = n, cnt, result = 0, mul = 1;
    while (check != 0)
    {
        check = check / 10;
        count++;
    }
    cnt = count;
    while (num != 0)
    {
        int temp = num%10;
        while (cnt != 0)
        {
            mul = mul * temp;
            cnt--;
        }
        result = result + mul;
        cnt = count;
        num = num / 10;
        mul = 1;
    }
    if (result == n)
        return 1;
    return 0;
}

int isPalindrome(int n)
{
    int num, result = 0, rem;
    num = n;
    while (num != 0)
    {
        rem = num % 10;
        result = result * 10 + rem;
        num = num / 10;
    }
    if (result == n)
        return 1;
    return 0;
}