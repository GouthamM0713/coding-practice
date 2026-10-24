#include <stdio.h>

int main() {
    int n, i;

    printf("Enter an integer greater than 1: ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("Enter a number greater than 1");
        return 0;
    }

    printf("Prime factors: ");

    for (i = 2; i <= n / i; i++) {
        while (n % i == 0) {
            printf("%d ", i);
            n /= i;
        }
    }

    if (n > 1)
        printf("%d", n);

    printf("\n");
    return 0;
}