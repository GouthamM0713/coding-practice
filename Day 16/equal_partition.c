#include <stdio.h>

int main() {
    int n, a[100], sum = 0;
    int dp[10001] = {0};

    scanf("%d", &n);

    if (n < 1 || n > 100) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);

        if (a[i] < 0) return 0;

        sum += a[i];
    }

    if (sum % 2 != 0) {
        printf("Equal partition not possible");
        return 0;
    }

    int target = sum / 2;

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = target; j >= a[i]; j--) {
            if (dp[j - a[i]])
                dp[j] = 1;
        }
    }

    if (dp[target])
        printf("Equal partition is possible");
    else
        printf("Equal partition is not possible");

    return 0;
}