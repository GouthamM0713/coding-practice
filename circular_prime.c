#include <stdio.h>

int isPrime(int n) {
    if (n < 2)
        return 0;

    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main(void) {
    int n, temp, digits = 0, divisor = 1;
    int circular = 1;

    printf("Enter a positive number: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Enter a positive number.\n");
        return 0;
    }

    temp = n;

    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    for (int i = 1; i < digits; i++)
        divisor *= 10;

    temp = n;

    for (int i = 0; i < digits; i++) {
        if (!isPrime(temp)) {
            circular = 0;
            break;
        }

        temp = (temp % 10) * divisor + temp / 10;
    }

    if (circular)
        printf("%d is a Circular Prime.\n", n);
    else
        printf("%d is not a Circular Prime.\n", n);

    return 0;
}
