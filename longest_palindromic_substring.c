#include <stdio.h>
#include <string.h>

int main(void) {
    char s[1000];
    int start = 0, maxlen = 0;

    printf("Enter a string: ");
    scanf("%999s", s);

    int n = (int)strlen(s);

    for (int c = 0; c < n; c++) {
        for (int type = 0; type < 2; type++) {
            int l = c;
            int r = c + type;

            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxlen) {
                    start = l;
                    maxlen = r - l + 1;
                }
                l--;
                r++;
            }
        }
    }

    printf("Longest palindrome: ");
    for (int i = start; i < start + maxlen; i++)
        putchar(s[i]);

    printf("\nLength: %d\n", maxlen);
    return 0;
}