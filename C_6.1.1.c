#include <stdio.h>

int get_GCD(int x, int y)
{
    int r;
    while (x % y != 0)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return y;
}

int fib(int n)
{
    int a = 1, b = 1;
    int result = 1;
    while (n > 2)
    {
        result = a + b;
        a = b;
        b = result;
        n--;
    }
    return result;
}

int main(void)
{
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d\n", get_GCD(x, y));
    int n;
    scanf("%d", &n);
    printf("%d\n", fib(n));
    return 0;
}