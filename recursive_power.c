#include <stdio.h>

long long power(int base, int exp) {
    if (exp == 0)
        return 1;

    return base * power(base, exp - 1);
}

int main() {
    int base, exp;

    printf("Enter base and non-negative exponent: ");
    scanf("%d %d", &base, &exp);

    if (exp < 0 || exp > 20) {
        printf("Exponent must be between 0 and 20");
    } else {
        printf("Result = %lld", power(base, exp));
    }

    return 0;
}