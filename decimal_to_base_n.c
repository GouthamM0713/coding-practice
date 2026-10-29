#include <stdio.h>

int main(void) {
    long long n, result = 0, place = 1;
    int base;

    printf("Enter a decimal number and base (2-9): ");
    if (scanf("%lld %d", &n, &base) != 2 ||
        n < 0 || base < 2 || base > 9) {
        printf("Invalid input.\n");
        return 1;
    }

    if (n == 0) {
        printf("Result: 0\n");
        return 0;
    }

    while (n > 0) {
        result += (n % base) * place;
        place *= 10;
        n /= base;
    }

    printf("Result: %lld\n", result);
    return 0;
}