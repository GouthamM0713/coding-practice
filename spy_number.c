#include <stdio.h>

int main() {
    int n, digit, sum = 0, product = 1;

    printf("Enter a non-negative number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid input");
        return 0;
    }

    do {
        digit = n % 10;
        sum += digit;
        product *= digit;
        n /= 10;
    } while (n > 0);

    if (sum == product)
        printf("Spy number\n");
    else
        printf("Not a Spy number\n");

    return 0;
}