#include <stdio.h>
#include <string.h>

#define D 256
#define Q 101

int main() {
    char text[200], pattern[100];

    scanf("%199s", text);
    scanf("%99s", pattern);

    int n = strlen(text);
    int m = strlen(pattern);

    if (m > n) {
        printf("Pattern not found");
        return 0;
    }

    int h = 1, p = 0, t = 0, found = 0;

    for (int i = 0; i < m - 1; i++)
        h = (h * D) % Q;

    for (int i = 0; i < m; i++) {
        p = (D * p + pattern[i]) % Q;
        t = (D * t + text[i]) % Q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t && strncmp(text + i, pattern, m) == 0) {
            printf("Pattern found at index %d\n", i);
            found = 1;
        }

        if (i < n - m) {
            t = (D * (t - text[i] * h) +
                 text[i + m]) % Q;

            if (t < 0) t += Q;
        }
    }

    if (!found)
        printf("Pattern not found");

    return 0;
}