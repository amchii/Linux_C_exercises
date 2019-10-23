#include <stdio.h>
#include <unistd.h>

#define LEN 8
int a[LEN] = {9, 8, 7, 6, 5, 4, 3, 2};

int partition(int start, int end)
{
    int pivot = a[start];
    while (start < end)
    {
        while (a[end] >= pivot && start < end)
        {
            end--;
        }
        a[start] = a[end];
        while (start < end && a[start] <= pivot)
        {
            start++;
        }
        a[end] = a[start];
    }
    a[start] = pivot;
    printf("array:%d %d %d %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
    return start;
}

int order_statistic(int start, int end, int k)
{
    int i;
    i = partition(start, end);
    if (k == i)
        return a[i];
    else if (k > i)
        return order_statistic(i + 1, end, k);
    else
        return order_statistic(start, i - 1, k);
}

int main(void)
{
    printf("%d\n", order_statistic(0, LEN - 1, 4));
    return 0;
}