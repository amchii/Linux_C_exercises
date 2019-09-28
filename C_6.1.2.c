#include <stdio.h>

int get_gewei(int x)
{
    return x % 10;
}

int get_shiwei(int x)
{
    return x / 10 % 10;
}

int main(void)
{
    int sum = 0;
    for (int i = 0; i < 100; i++)
    {
        if (get_gewei(i) == 9)
        {
            sum++;
        }
        if (get_shiwei(i) == 9)
        {
            sum++;
        }
    }
    printf("%d\n", sum);
    return 0;
}