#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, amount;

    printf("Enter number of coin types: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) return 1;

    int coins[100];

    printf("Enter coin denominations: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
        if (coins[i] <= 0) {
            printf("Coins must be positive\n");
            return 1;
        }
    }

    printf("Enter amount: ");
    scanf("%d", &amount);

    if (amount < 0 || amount > 1000000) return 1;

    int *dp = malloc((amount + 1) * sizeof(int));
    if (!dp) return 1;

    for (int i = 0; i <= amount; i++)
        dp[i] = amount + 1;

    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
        for (int j = 0; j < n; j++)
            if (coins[j] <= i && dp[i - coins[j]] + 1 < dp[i])
                dp[i] = dp[i - coins[j]] + 1;

    if (dp[amount] > amount)
        printf("Amount cannot be formed\n");
    else
        printf("Minimum coins: %d\n", dp[amount]);

    free(dp);
    return 0;
}