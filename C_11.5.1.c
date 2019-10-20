#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 8
int a[N] = {586, 512, 12, 32, 62, 13, 9, 6};

int get_min(void)
{
    int min = a[0];
    for (int i = 0; i < N; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    return min;
}

int get_sec_min(void)
{
    int min = a[0];
    int sec_min, flag = 0;
    for (int i = 0; i < N; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            flag = i;
        }
    }
    int j = 0;
    if (flag > 0)
    {
        sec_min = a[0];
    }
    else
    {
        sec_min = a[1];
    }

    while (j < N)
    {
        if (j == flag)
        {
            j++;
            continue;
        }

        if (a[j] < sec_min)
        {
            sec_min = a[j];
        }
        j++;
    }

    return sec_min;
}

int main(void)
{
    printf("min:%d\n", get_min());
    printf("sec_min:%d\n", get_sec_min());
    return 0;
}