#include <stdio.h>
#include <limits.h>

int main(void) {
    unsigned long long n;

    printf("Enter a positive integer: ");
    if (scanf("%llu", &n) != 1 || n == 0) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Collatz sequence: ");

    while (n != 1) {
        printf("%llu ", n);

        if (n % 2 == 0) {
            n /= 2;
        } else {
            if (n > (ULLONG_MAX - 1) / 3) {
                printf("\nOverflow risk.\n");
                return 1;
            }
            n = 3 * n + 1;
        }
    }

    printf("1\n");
    return 0;
}