#include <stdio.h>

int main(void) {
    int n, r, i;
    unsigned long long result = 1;

    printf("Enter n and r (0 <= r <= n <= 60): ");
    if (scanf("%d %d", &n, &r) != 2 ||
        n < 0 || n > 60 || r < 0 || r > n) {
        printf("Invalid input.\n");
        return 1;
    }

    if (r > n - r)
        r = n - r;

    for (i = 1; i <= r; i++)
        result = result * (n - r + i) / i;

    printf("C(%d, %d) = %llu\n", n, r, result);
    return 0;
}