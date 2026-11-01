#include <stdio.h>

int main() {
    int eggs, floors;
    int dp[11][101] = {0};

    scanf("%d%d", &eggs, &floors);

    if (eggs < 1 || eggs > 10 ||
        floors < 0 || floors > 100)
        return 0;

    for (int i = 1; i <= eggs; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    for (int j = 1; j <= floors; j++)
        dp[1][j] = j;

    for (int i = 2; i <= eggs; i++) {
        for (int j = 2; j <= floors; j++) {
            dp[i][j] = 100000;

            for (int k = 1; k <= j; k++) {
                int attempts = 1 +
                    (dp[i - 1][k - 1] > dp[i][j - k]
                    ? dp[i - 1][k - 1]
                    : dp[i][j - k]);

                if (attempts < dp[i][j])
                    dp[i][j] = attempts;
            }
        }
    }

    printf("Minimum attempts = %d", dp[eggs][floors]);

    return 0;
}