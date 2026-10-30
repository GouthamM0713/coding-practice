#include <stdio.h>
#include <limits.h>

int main() {
    int n, p[20];
    long long dp[20][20] = {0};

    scanf("%d", &n);

    if (n < 1 || n > 19) return 0;

    for (int i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    for (int i = 1; i <= n; i++)
        if (p[i] <= 0) return 0;

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n-len+1; i++) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;

            for (int k = i; k < j; k++) {
                long long cost =
                    dp[i][k] + dp[k+1][j] +
                    1LL * p[i-1] * p[k] * p[j];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    printf("Minimum multiplication cost = %lld",
           dp[1][n]);

    return 0;
}