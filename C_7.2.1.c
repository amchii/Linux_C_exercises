#include <stdio.h>
#include <math.h>

struct complex_struct
{
    double x, y;
};

double real_part(struct complex_struct z)
{
    return z.x;
}

double img_part(struct complex_struct z)
{
    return z.y;
}

double magnitute(struct complex_struct z)
{
    return sqrt(pow(z.x, 2) + pow(z.y, 2));
}

double angle(struct complex_struct z)
{
    return atan2(z.y, z.x);
}

struct complex_struct make_from_real_img(double x, double y)
{
    struct complex_struct z;
    z.x = x;
    z.y = y;
    return z;
}

struct complex_struct make_from_mag_ang(double r, double A)
{
    struct complex_struct z;
    z.x = r * cos(A);
    z.y = r * sin(A);
    return z;
}

struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2)
{
    return make_from_real_img(real_part(z1) + real_part(z2), img_part(z1) + img_part(z2));
}

struct complex_struct sub_complex(struct complex_struct z1, struct complex_struct z2)
{
    return make_from_real_img(real_part(z1) - real_part(z2), img_part(z1) - img_part(z2));
}

struct complex_struct mul_complex(struct complex_struct z1, struct complex_struct z2)
{
    return make_from_mag_ang(magnitute(z1) * magnitute(z2), angle(z1) + angle(z2));
}

struct complex_struct div_complex(struct complex_struct z1, struct complex_struct z2)
{
    return make_from_mag_ang(magnitute(z1) / magnitute(z2), angle(z1) - angle(z2));
}

void print_complex(struct complex_struct z)
{
    double x, y;
    x = real_part(z);
    y = img_part(z);
    if (y > 0)
    {
        if (x != 0)
            printf("%.1f+%.1fi\n", x, y);
        else
            printf("%.1f\n", y);
    }
    else if (y < 0)
    {
        if (x != 0)
            printf("%.1f%.1fi\n", x, y);
        else
            printf("%.1fi\n", y);
    }
    else
        printf("%.1f\n", x);
}

int main(void)
{
    double x, y;
    printf("实部：");
    scanf("%lf", &x);
    printf("虚部：");
    scanf("%lf", &y);
    print_complex(make_from_real_img(x, y));
    return 0;
}
