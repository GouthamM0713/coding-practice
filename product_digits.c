#include <stdio.h>

int main() {
    int n, digit, product = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0)
        n = -n;

    do {
        digit = n % 10;
        product *= digit;
        n /= 10;
    } while (n > 0);

    printf("Product of digits = %d\n", product);
    return 0;
}