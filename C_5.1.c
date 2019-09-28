#include <stdio.h>
#include <math.h>

int is_leap_year(int year)
{
    if (year % 4 == 0 && year % 100)
        return 1;
    else if (year % 400 == 0)
    {
        return 1;
    }
    return 0;
}

double myround(double x)
{
    if (x > 0.0)
    {
        if (x - floor(x) >= 0.5)
        {
            return ceil(x);
        }
        else
        {
            return floor(x);
        }
    }
    else
    {
        if (ceil(x) - x >= 0.5)
        {
            return floor(x);
        }
        else
        {
            return ceil(x);
        }
    }
}

int main(void)
{
    double x;
    scanf("%lf", &x);
    printf("%lf\n", myround(x));
    return 0;
}
