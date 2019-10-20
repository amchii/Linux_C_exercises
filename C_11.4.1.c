#include <stdio.h>

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

void quick_sort(int start, int end)
{
    int mid;
    if (end > start)
    {
        mid = partition(start, end);
        quick_sort(start, mid - 1);
        quick_sort(mid + 1, end);
    }
}

int main(void)
{
    printf("array:%d %d %d %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
    quick_sort(0, LEN - 1);
    printf("array:%d %d %d %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
    return 0;
}