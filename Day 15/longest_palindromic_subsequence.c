#include <stdio.h>
#include <string.h>

int main() {
    char s[200];
    int dp[200][200] = {0};

    scanf("%199s", s);

    int n = strlen(s);

    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            if (s[i] == s[j]) {
                dp[i][j] = 2 +
                    (len == 2 ? 0 : dp[i + 1][j - 1]);
            } else {
                dp[i][j] = dp[i + 1][j] > dp[i][j - 1]
                    ? dp[i + 1][j]
                    : dp[i][j - 1];
            }
        }
    }

    printf("Longest Palindromic Subsequence = %d",
           dp[0][n - 1]);

    return 0;
}