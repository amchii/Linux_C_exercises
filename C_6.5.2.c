#include <stdio.h>

void repeat_char(int n, char c)
{
    for (int i = 0; i < n; i++)
    {
        printf("%-4c", c);
    }
    printf("\n");
}

void diamond(int n, char c)
{
    if (n % 2 == 0)
    {
        printf("请输入奇数！\n");
        return;
    }

    for (int i = 1; i <= n; i += 2)
    {
        for (int j = (n - i) / 2; j > 0; j--)
        {
            printf("%4c", ' ');
        }
        repeat_char(i, c);
    }
    for (int i = n - 2; i > 0; i -= 2)
    {
        for (int j = (n - i) / 2; j > 0; j--)
        {
            printf("%4c", ' ');
        }
        repeat_char(i, c);
    }
}

int main(void)
{
    int n;
    char c;
    scanf("%d %c", &n, &c);
    diamond(n, c);
    return 0;
}