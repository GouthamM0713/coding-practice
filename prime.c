#include <stdio.h>

int main(void) {
    int n, isPrime = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 2) {
        isPrime = 0;
    } else {
        for (int i = 2; i <= n / i; i++) {
            if (n % i == 0) {
                isPrime = 0;
                break;
            }
        }
    }

    if (isPrime) {
        printf("Prime number\n");
    } else {
        printf("Not a prime number\n");
    }

    return 0;
}
