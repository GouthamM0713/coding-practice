#include <stdio.h>
#include <string.h>

int main() {
    char s[100], p[100];
    int dp[101][101] = {0};

    scanf("%99s", s);
    scanf("%99s", p);

    int n = strlen(s);
    int m = strlen(p);

    dp[0][0] = 1;

    for (int j = 1; j <= m; j++)
        if (p[j-1] == '*')
            dp[0][j] = dp[0][j-1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (p[j-1] == '?' || p[j-1] == s[i-1])
                dp[i][j] = dp[i-1][j-1];
            else if (p[j-1] == '*')
                dp[i][j] = dp[i][j-1] ||
                           dp[i-1][j];
        }
    }

    if (dp[n][m])
        printf("Pattern matches");
    else
        printf("Pattern does not match");

    return 0;
}