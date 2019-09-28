#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_result(int f1, int f2, int f3, int f4)
{
    if (f1)
        return 1;
    else if (f2)
        return 1;
    else if (f3)
        return 1;
    else if (f4)
        return 1;
    else
        return 0;
}

int get_result_3(int f1, int f2, int f3)
{
    if (f1)
        return 1;
    else if (f2)
        return 1;
    else if (f3)
        return 1;
    else
        return 0;
}

int main()
{
    int x, y, z;
    int f1, f2, f3, f4;
    int result;
    int flag[] = {0, 0, 0};
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 1000; i++)
    {
        x = rand() % 101 - 50;
        y = rand() % 101 - 50;
        z = rand() % 101 - 50;
        // printf("%d,%d,%d\n", x, y, z);
        f1 = (x < 3) && (y > 3);
        f2 = (x >= 3) && (y >= 3);
        f3 = (z > 3) && (x >= 3);
        f4 = (z <= 3) && (y >= 3);
        /* printf("%d,%d,%d,%d\n", f1, f2, f3, f4);
        printf("result:%d\n", get_result(f1, f2, f3, f4)); */
        // printf("%d,%d,%d\n", flag[0], flag[1], flag[2]);
        result = get_result(f1, f2, f3, f4);
        for (int j = 0; j < 3; j++)
        {
            if (j = 0)
            {
                if (result != get_result_3(f1, f3, f4))
                {
                    flag[0]++;
                }
            }
            if (j = 1)
            {
                if (result != get_result_3(f1, f2, f4))
                {
                    flag[1]++;
                }
            }
            if (j = 2)
            {
                if (result != get_result_3(f1, f2, f3))
                {
                    flag[2]++;
                }
            }
        }
    }
    printf("f2:%d,f3:%d,f4:%d\n", flag[0], flag[1], flag[2]);
    return 0;
}