
#include <stdio.h>

int main(void) {
    long long n, x = 0;

    printf("Enter an integer: ");
    scanf("%lld", &n);

    while (1) {
        long long cube = x * x * x;

        if (cube == n) {
            printf("%lld is a perfect cube\n", n);
            return 0;
        }

        if (cube > n || x > 2097152)
            break;

        x++;
    }

    x = 0;

    while (1) {
        long long cube = -(x * x * x);

        if (cube == n) {
            printf("%lld is a perfect cube\n", n);
            return 0;
        }

        if (cube < n || x > 2097152)
            break;

        x++;
    }

    printf("%lld is not a perfect cube\n", n);
    return 0;
}