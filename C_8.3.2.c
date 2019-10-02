#include <stdio.h>

#define N 4
#define M 2
int a[N] = {1, 2, 3, 4};

void print_array_all_permutation(int n)
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
            print_array_all_permutation(n - 1);
            for (int i = 0; i < N; i++)
                a[i] = b[i];
        }
    }
}

/* 
    这题的思路类似全排列,比如对于一个数组 a={1,2,3,4,5}, M=3, N=5,要求打印3/5的排列：
        把第一个数放在最前面,准备打印1,x,x,再打印{2,3,4,5}的2/4排列(1,2,x),打印
        {3,4,5}的1/3排列(1,2,3),(1,2,4),(1,2,5).要注意的是这里对应的Base Case需
        要将第M个数(这里即第3个)替换为a[M-1],a[M]...a[N-1]分别打印.
*/
void print_array_permutation(int n, int m)
{
    if (m == 1)
    {
        for (int j = M - 1; j < N; j++)
        {
            a[M - 1] = a[j];
            for (int i = 0; i < M; i++)
            {
                printf("%d ", a[i]);
            }
            printf("\n");
        }
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
            print_array_permutation(n - 1, m - 1);
            for (int i = 0; i < N; i++)
                a[i] = b[i];
        }
    }
}

int main(int argc, char const *argv[])
{
    print_array_all_permutation(N);
    print_array_permutation(N, M);
    return 0;
}
