#include <stdio.h>

int main() {
    int n, coins[50], amount;
    long long dp[10001] = {0};

    scanf("%d", &n);

    if (n < 1 || n > 50) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
        if (coins[i] <= 0) return 0;
    }

    scanf("%d", &amount);

    if (amount < 0 || amount > 10000)
        return 0;

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    printf("Number of ways = %lld", dp[amount]);

    return 0;
}