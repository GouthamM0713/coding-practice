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
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 2)
        n = 2;
    else
        n++;

    while (!isPrime(n))
        n++;

    printf("Next prime number = %d\n", n);

    return 0;
}
