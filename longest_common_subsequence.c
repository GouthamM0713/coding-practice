#include <stdio.h>
#include <string.h>

#define MAX 100

int main(void) {
    char a[MAX], b[MAX];
    int dp[MAX + 1][MAX + 1] = {0};
    int i, j, len;
    char result[MAX];

    printf("Enter first string: ");
    if (scanf("%99s", a) != 1)
        return 1;

    printf("Enter second string: ");
    if (scanf("%99s", b) != 1)
        return 1;

    for (i = 1; a[i - 1] != '\0'; i++) {
        for (j = 1; b[j - 1] != '\0'; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else if (dp[i - 1][j] >= dp[i][j - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i][j - 1];
        }
    }

    len = dp[strlen(a)][strlen(b)];
    result[len] = '\0';

    i = (int)strlen(a);
    j = (int)strlen(b);

    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            result[--len] = a[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("LCS length = %d\n", dp[strlen(a)][strlen(b)]);
    printf("Longest common subsequence = %s\n", result);

    return 0;
}