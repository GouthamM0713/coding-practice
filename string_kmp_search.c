#include <stdio.h>
#include <string.h>

#define MAX 500

void buildLPS(char pattern[], int lps[]) {
    int len = 0;
    int i = 1;
    int m = (int)strlen(pattern);

    lps[0] = 0;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else if (len != 0) {
            len = lps[len - 1];
        } else {
            lps[i] = 0;
            i++;
        }
    }
}

int main(void) {
    char text[MAX], pattern[MAX];
    int lps[MAX];
    int i = 0, j = 0, found = 0;
    int n, m;

    printf("Enter text (no spaces): ");
    if (scanf("%499s", text) != 1)
        return 1;

    printf("Enter pattern (no spaces): ");
    if (scanf("%499s", pattern) != 1)
        return 1;

    n = (int)strlen(text);
    m = (int)strlen(pattern);

    buildLPS(pattern, lps);

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            found = 1;
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    if (!found)
        printf("Pattern not found.\n");

    return 0;
}