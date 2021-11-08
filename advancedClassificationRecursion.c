#include <math.h>
#include <stdio.h>
#include "NumClass.h"

int helpPalindrome(int num, int len)
{
    if (len == 1){
        return num;
    }
    len -= 1;
    return (((num % 10) * pow(10, len)) + helpPalindrome(num / 10, len));
}

int isPalindrome(int n)
{
    int num = n, result, lenght = 0;
    while (num != 0)
    {
        lenght++;
        num /= 10;
    }

    result = helpPalindrome(n, lenght);
    if (n == result)
        return 1;
    return 0;
}

int helpTheArmstrong(int num, int lenght)
{
    if (num == 0)
        return 0;
    else
        return pow(num % 10, lenght) + helpTheArmstrong(num / 10, lenght);
}

int isArmstrong(int n)
{
    int temp = n, lenght = 0, result;
    while (temp != 0)
    {
        temp = temp / 10;
        lenght++;
    }
    result = helpTheArmstrong(n, lenght);
    if (result == n)
        return 1;
    return 0;
}