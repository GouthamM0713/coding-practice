#include <stdio.h>

int main() {
    int n, price[101], dp[101] = {0};

    scanf("%d", &n);

    if (n < 1 || n > 100) return 0;

    for (int i = 1; i <= n; i++)
        scanf("%d", &price[i]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            int value = price[j] + dp[i - j];

            if (value > dp[i])
                dp[i] = value;
        }
    }

    printf("Maximum rod cutting profit = %d", dp[n]);

    return 0;
}