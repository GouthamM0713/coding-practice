#include <stdio.h>
#include <string.h>

int main() {
    char s[200], t[400];
    int p[400] = {0};

    scanf("%199s", s);

    int n = strlen(s);
    int k = 0;

    t[k++] = '^';

    for (int i = 0; i < n; i++) {
        t[k++] = '#';
        t[k++] = s[i];
    }

    t[k++] = '#';
    t[k++] = '$';
    t[k] = '\0';

    int center = 0, right = 0;

    for (int i = 1; i < k - 1; i++) {
        int mirror = 2 * center - i;

        if (i < right)
            p[i] = p[mirror] < right - i
                ? p[mirror] : right - i;

        while (t[i + 1 + p[i]] == t[i - 1 - p[i]])
            p[i]++;

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }

    int maxLen = 0, best = 0;

    for (int i = 1; i < k - 1; i++) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            best = i;
        }
    }

    int start = (best - maxLen) / 2;

    printf("Longest palindrome: ");
    for (int i = start; i < start + maxLen; i++)
        printf("%c", s[i]);

    printf("\nLength = %d", maxLen);

    return 0;
}