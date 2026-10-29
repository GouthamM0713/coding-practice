#include <stdio.h>

int main(void) {
    int n, capacity;
    int w[51], v[51];
    int dp[51][1001] = {0};

    printf("Enter number of items and capacity: ");
    scanf("%d %d", &n, &capacity);

    if (n < 1 || n > 50 || capacity < 0 || capacity > 1000)
        return 1;

    for (int i = 1; i <= n; i++) {
        printf("Enter weight and value of item %d: ", i);
        scanf("%d %d", &w[i], &v[i]);

        if (w[i] <= 0 || v[i] < 0) return 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int c = 0; c <= capacity; c++) {
            dp[i][c] = dp[i - 1][c];

            if (w[i] <= c) {
                int value = v[i] + dp[i - 1][c - w[i]];
                if (value > dp[i][c])
                    dp[i][c] = value;
            }
        }
    }

    printf("Maximum value: %d\n", dp[n][capacity]);
    return 0;
}