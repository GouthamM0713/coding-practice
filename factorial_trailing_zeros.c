#include <stdio.h>

int main(void) {
    unsigned int n;
    unsigned long long count = 0;
    unsigned long long divisor = 5;

    printf("Enter a non-negative integer: ");
    if (scanf("%u", &n) != 1)
        return 1;

    while (n / divisor > 0) {
        count += n / divisor;

        if (divisor > n / 5)
            break;

        divisor *= 5;
    }

    printf("Trailing zeros in %u! = %llu\n", n, count);
    return 0;
}