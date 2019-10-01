#include <stdio.h>
#include <stdlib.h>

#define N 20

int a[N];

void gen_random(int upper_bound)
{
    int i;
    for (i = 0; i < N; i++)
        a[i] = rand() % upper_bound;
}

int main(void)
{
    int histogram[10] = {0};
    int max = 0;
    gen_random(10);
    for (int i = 0; i < N; i++)
    {
        histogram[a[i]]++;
        if (max < histogram[a[i]])
            max = histogram[a[i]];
    }
    for (int j = 0; j < 10; j++)
        printf("%d\t", j);
        
    printf("\n\n");
    
    for (int i = 1; i <= max; i++)
    {
        for (int j = 0; j < 10; j++)
            if (histogram[j] >= i)
            {
                printf("*\t");
            }
            else
            {
                printf(" \t");
            }
        printf("\n");
    }

    return 0;
}