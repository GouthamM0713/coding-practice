#include <stdio.h>

int main(void) {
    int low, high;
    long long a = 0, b = 1, next;

    printf("Enter lower and upper limits (0-90): ");
    if (scanf("%d %d", &low, &high) != 2 ||
        low < 0 || high < low || high > 90) {
        printf("Invalid range.\n");
        return 1;
    }

    printf("Fibonacci numbers: ");

    while (a <= high) {
        if (a >= low)
            printf("%lld ", a);

        next = a + b;
        a = b;
        b = next;
    }

    printf("\n");
    return 0;
}