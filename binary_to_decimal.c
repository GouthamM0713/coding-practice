#include <stdio.h>

int main() {
    long long binary;
    int decimal = 0, base = 1, digit;

    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    while (binary > 0) {
        digit = binary % 10;

        if (digit != 0 && digit != 1) {
            printf("Invalid binary number\n");
            return 0;
        }

        decimal += digit * base;
        base *= 2;
        binary /= 10;
    }

    printf("Decimal = %d\n", decimal);
    return 0;
}