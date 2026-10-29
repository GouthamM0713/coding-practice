#include <stdio.h>

long long extendedGCD(long long a, long long b,
                      long long *x, long long *y) {
    long long x1, y1, gcd;

    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    gcd = extendedGCD(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

int main(void) {
    long long a, b, x, y, gcd;

    printf("Enter two non-negative integers: ");
    if (scanf("%lld %lld", &a, &b) != 2 ||
        a < 0 || b < 0 || (a == 0 && b == 0)) {
        printf("Invalid input.\n");
        return 1;
    }

    gcd = extendedGCD(a, b, &x, &y);

    printf("GCD = %lld\n", gcd);
    printf("Bézout coefficients: x = %lld, y = %lld\n", x, y);
    printf("%lld(%lld) + %lld(%lld) = %lld\n",
           a, x, b, y, gcd);

    return 0;
}