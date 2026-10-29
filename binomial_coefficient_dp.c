#include <stdio.h>

int main(void) {
    int n, r;
    unsigned long long dp[61] = {0};

    printf("Enter n and r (0 <= r <= n <= 60): ");
    scanf("%d %d", &n, &r);

    if (n < 0 || n > 60 || r < 0 || r > n) {
        printf("Invalid input\n");
        return 1;
    }

    dp[0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = i; j >= 1; j--)
            dp[j] += dp[j - 1];

    printf("C(%d, %d) = %llu\n", n, r, dp[r]);
    return 0;
}