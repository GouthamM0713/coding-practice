#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[50][100];

    scanf("%d", &n);
    if (n < 1 || n > 50) return 0;

    for (int i = 0; i < n; i++)
        scanf("%99s", s[i]);

    int len = strlen(s[0]);

    for (int i = 1; i < n; i++) {
        int j = 0;

        while (j < len && s[i][j] &&
               s[0][j] == s[i][j])
            j++;

        len = j;
    }

    if (len == 0)
        printf("No common prefix");
    else {
        printf("Longest common prefix: ");
        for (int i = 0; i < len; i++)
            printf("%c", s[0][i]);
    }

    return 0;
}