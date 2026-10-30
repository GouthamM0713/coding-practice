#include <stdio.h>
#include <string.h>

int main() {
    char s[200];
    int z[200];

    scanf("%199s", s);

    int n = strlen(s);
    int l = 0, r = 0;

    z[0] = 0;

    for (int i = 1; i < n; i++) {
        if (i <= r)
            z[i] = (z[i-l] < r-i+1) ?
                    z[i-l] : r-i+1;
        else
            z[i] = 0;

        while (i + z[i] < n &&
               s[z[i]] == s[i+z[i]])
            z[i]++;

        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", z[i]);

    return 0;
}