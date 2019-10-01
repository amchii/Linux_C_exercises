#include <stdio.h>
#include <math.h>

enum corodinate_type
{
    RECTANGULAR,
    POLAR
};

struct complex_struct
{
    enum corodinate_type t;
    double a, b;
};

double real_part(struct complex_struct z)
{
    if (z.t == RECTANGULAR)
    {
        return z.a;
    }
    else
    {
        return z.a * cos(z.b);
    }
}

double magnitude(struct complex_struct z)
{
    if (z.t == RECTANGULAR)
    {
        return sqrt(pow(z.a, 2) + pow(z.b, 2));
    }
    else
    {
        return z.a;
    }
}

struct complex_struct make_from_real_img(double x, double y)
{
    struct complex_struct z;
    z.t = RECTANGULAR;
    z.a = x;
    z.b = y;
    return z;
}
struct complex_struct make_from_mag_ang(double r, double A)
{
    struct complex_struct z;
    z.t = POLAR;
    z.a = r;
    z.b = A;
    return z;
}

int main(void)
{
    struct complex_struct z1, z2;
    z1 = make_from_real_img(3, 4);
    z2 = make_from_mag_ang(5, atan2(4, 3));
    printf("%f %f\n", real_part(z1), real_part(z2));
    printf("%f %f\n", magnitude(z1), magnitude(z2));
    return 0;
}
