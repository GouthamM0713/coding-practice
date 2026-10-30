#include <stdio.h>

int main() {
    int n, a[50], target;
    int dp[10001] = {0};

    scanf("%d", &n);

    if (n < 1 || n > 50) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < 0) return 0;
    }

    scanf("%d", &target);

    if (target < 0 || target > 10000)
        return 0;

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = target; j >= a[i]; j--) {
            if (dp[j-a[i]])
                dp[j] = 1;
        }
    }

    if (dp[target])
        printf("Subset with given sum exists");
    else
        printf("Subset with given sum does not exist");

    return 0;
}