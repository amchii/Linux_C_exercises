#include <stdio.h>
#include <stdlib.h>

struct rational
{
    int x, y;
};

int GCD(int x, int y)
{
    if (x % y == 0)
    {
        return y;
    }
    else
    {
        return GCD(y, x % y);
    }
}

int numerator(struct rational r)
{
    return r.x;
}

int denominator(struct rational r)
{
    return r.y;
}

struct rational make_rational(int x, int y)
{
    struct rational r;
    r.x = x / GCD(x, y);
    r.y = y / GCD(x, y);
    return r;
}

struct rational add_rational(struct rational r1, struct rational r2)
{
    return make_rational(numerator(r1) * denominator(r2) + numerator(r2) * denominator(r1), denominator(r1) * denominator(r2));
}

struct rational sub_rational(struct rational r1, struct rational r2)
{
    return make_rational(numerator(r1) * denominator(r2) - numerator(r2) * denominator(r1), denominator(r1) * denominator(r2));
}

struct rational mul_rational(struct rational r1, struct rational r2)
{
    return make_rational(numerator(r1) * numerator(r2), denominator(r1) * denominator(r2));
}

struct rational div_rational(struct rational r1, struct rational r2)
{
    return mul_rational(r1, make_rational(denominator(r2), numerator(r2)));
}

void print_rational(struct rational r)
{
    if (denominator(r) == 0)
    {
        printf("分母不能为0!\n");
        return;
    }

    if (numerator(r) % denominator(r) == 0)
    {
        printf("%d\n", numerator(r) / denominator(r));
    }
    else if (numerator(r) / denominator(r) < 0)
    {
        printf("-%d/%d\n", abs(numerator(r)), abs(denominator(r)));
    }
    else
    {
        printf("%d/%d\n", numerator(r), denominator(r));
    }
}

int main(void)
{
    struct rational r1 = make_rational(1, 8), r2 = make_rational(-1, 8);
    print_rational(add_rational(r1, r2));
    print_rational(sub_rational(r1, r2));
    print_rational(mul_rational(r1, r2));
    print_rational(div_rational(r1, r2));
    return 0;
}
