#include <stdio.h>

#define N 4
int a[N] = {1, 2, 3, 4};

void print_array_permutation(int n)
{

    if (n == 1)
    {
        for (int i = 0; i < N; i++)
            printf("%d ", a[i]);

        printf("\n");
    }
    else
    {
        int b[N];
        for (int i = 0; i < N; i++)
            b[i] = a[i];
        for (int i = N - n; i < N; i++)
        {
            int temp;
            temp = a[N - n];
            a[N - n] = a[i];
            a[i] = temp;
            print_array_permutation(n - 1);
            for (int i = 0; i < N; i++)
                a[i] = b[i];
        }
    }
}

int main(int argc, char const *argv[])
{
    // print_array_permutation(N, a);
    print_array_permutation(N);
    return 0;
}
