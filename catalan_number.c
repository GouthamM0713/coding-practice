#include <stdio.h>

int main(void) {
    int n, i, j;
    unsigned long long c[37] = {0};

    printf("Enter n (0-36): ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 36) {
        printf("Enter a value between 0 and 36.\n");
        return 1;
    }

    c[0] = 1;

    for (i = 1; i <= n; i++) {
        for (j = 0; j < i; j++) {
            c[i] += c[j] * c[i - 1 - j];
        }
    }

    printf("Catalan number C(%d) = %llu\n", n, c[n]);
    return 0;
}