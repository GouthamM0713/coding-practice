#include <stdio.h>

int main() {
    int n, a[100], dp[100];

    scanf("%d", &n);

    if (n < 1 || n > 100) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < 0) return 0;
        dp[i] = 100000;
    }

    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1;
             j < n && j <= i + a[i]; j++) {

            if (dp[i] + 1 < dp[j])
                dp[j] = dp[i] + 1;
        }
    }

    if (dp[n - 1] == 100000)
        printf("End cannot be reached");
    else
        printf("Minimum jumps = %d", dp[n - 1]);

    return 0;
}