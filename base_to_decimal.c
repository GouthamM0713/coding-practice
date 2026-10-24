#include <stdio.h>

int main(void) {
    long long n, result = 0, place = 1;
    int base, digit;

    printf("Enter a number and its base (2-10): ");
    if (scanf("%lld %d", &n, &base) != 2 ||
        n < 0 || base < 2 || base > 10) {
        printf("Invalid input.\n");
        return 1;
    }

    while (n > 0) {
        digit = n % 10;

        if (digit >= base) {
            printf("Invalid digit for this base.\n");
            return 1;
        }

        result += digit * place;
        place *= base;
        n /= 10;
    }

    printf("Decimal: %lld\n", result);
    return 0;
}