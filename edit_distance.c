#include <stdio.h>
#include <string.h>

int main(void) {
    char a[101], b[101];
    int dp[101][101];

    printf("Enter first word: ");
    scanf("%100s", a);

    printf("Enter second word: ");
    scanf("%100s", b);

    int n = (int)strlen(a);
    int m = (int)strlen(b);

    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else {
                int x = dp[i - 1][j];
                int y = dp[i][j - 1];
                int z = dp[i - 1][j - 1];

                int min = x < y ? x : y;
                if (z < min) min = z;

                dp[i][j] = 1 + min;
            }
        }
    }

    printf("Edit distance: %d\n", dp[n][m]);
    return 0;
}