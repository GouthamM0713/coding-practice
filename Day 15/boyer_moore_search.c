#include <stdio.h>
#include <string.h>

int main() {
    char text[200], pattern[100];
    int bad[256];

    scanf("%199s", text);
    scanf("%99s", pattern);

    int n = strlen(text);
    int m = strlen(pattern);

    if (m > n) {
        printf("Pattern not found");
        return 0;
    }

    for (int i = 0; i < 256; i++)
        bad[i] = -1;

    for (int i = 0; i < m; i++)
        bad[(unsigned char)pattern[i]] = i;

    int found = 0;
    int shift = 0;

    while (shift <= n - m) {
        int j = m - 1;

        while (j >= 0 &&
               pattern[j] == text[shift + j])
            j--;

        if (j < 0) {
            printf("Pattern found at index %d\n", shift);
            found = 1;

            shift += (shift + m < n)
                ? m - bad[(unsigned char)text[shift + m]]
                : 1;
        } else {
            int move = j -
                bad[(unsigned char)text[shift + j]];

            shift += move > 1 ? move : 1;
        }
    }

    if (!found)
        printf("Pattern not found");

    return 0;
}