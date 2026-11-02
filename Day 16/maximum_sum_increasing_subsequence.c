#include <stdio.h>

int main() {
    int n, a[100], dp[100];

    scanf("%d", &n);

    if (n < 1 || n > 100) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        dp[i] = a[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] &&
                dp[j] + a[i] > dp[i]) {
                dp[i] = dp[j] + a[i];
            }
        }
    }

    int max = dp[0];

    for (int i = 1; i < n; i++)
        if (dp[i] > max)
            max = dp[i];

    printf("Maximum increasing subsequence sum = %d", max);

    return 0;
}