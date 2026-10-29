#include <stdio.h>

int main(void) {
    long long a, b, m, result = 1;

    printf("Enter base, exponent and modulus: ");
    if (scanf("%lld %lld %lld", &a, &b, &m) != 3 ||
        a < 0 || b < 0 || m <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    a %= m;

    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % m;

        a = (a * a) % m;
        b /= 2;
    }

    printf("Result = %lld\n", result);
    return 0;
}