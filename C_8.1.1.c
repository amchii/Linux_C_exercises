#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[4] = {1, 2, 3, 4};
    int b[4];
    for (int i = 0; i < 4; i++)
    {
        b[i] = a[i];
    }
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", b[i]);
    }
    return 0;
}
