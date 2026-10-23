#include <stdio.h>

int isPrime(int n) {
    if (n < 2) return 0;

    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main(void) {
    int limit = 50;

    for (int i = 2; i + 2 <= limit; i++) {
        if (isPrime(i) && isPrime(i + 2))
            printf("(%d, %d)\n", i, i + 2);
    }

    return 0;
}
