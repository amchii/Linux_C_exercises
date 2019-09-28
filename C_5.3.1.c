#include <stdio.h>

int get_GCD(int x, int y)
{
    if (x % y == 0)
    {
        return y;
    }
    else
    {
        return get_GCD(y, x % y);
    }
}

int main(int argc, char const *argv[])
{
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d\n", get_GCD(x, y));
    return 0;
}
