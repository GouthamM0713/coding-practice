#include <stdio.h>

int main(void) {
    int a[100], dp[100];
    int n, i, j, best = 0;

    printf("Enter array size (1-100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100)
        return 1;

    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1)
            return 1;
        dp[i] = 1;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (a[j] < a[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }

        if (dp[i] > best)
            best = dp[i];
    }

    printf("Longest increasing subsequence length: %d\n", best);
    return 0;
}