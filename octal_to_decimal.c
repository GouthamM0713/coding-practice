#include <stdio.h>

int main() {
    long long octal;
    int digit, decimal = 0, base = 1;

    printf("Enter an octal number: ");
    scanf("%lld", &octal);

    if (octal < 0) {
        printf("Invalid input");
        return 0;
    }

    if (octal == 0) {
        printf("Decimal = 0");
        return 0;
    }

    while (octal > 0) {
        digit = octal % 10;

        if (digit > 7) {
            printf("Invalid octal number");
            return 0;
        }

        decimal += digit * base;
        base *= 8;
        octal /= 10;
    }

    printf("Decimal = %d", decimal);

    return 0;
}