#include <stdio.h>

int main() {
    int a[20], b[20], result[40] = {0};
    int m, n;

    scanf("%d", &m);
    if (m < 0 || m >= 20) return 0;

    for (int i = 0; i <= m; i++)
        scanf("%d", &a[i]);

    scanf("%d", &n);
    if (n < 0 || n >= 20) return 0;

    for (int i = 0; i <= n; i++)
        scanf("%d", &b[i]);

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            result[i + j] += a[i] * b[j];

    printf("Result: ");

    for (int i = m + n; i >= 0; i--) {
        if (result[i] != 0) {
            printf("%dx^%d", result[i], i);

            if (i > 0)
                printf(" + ");
        }
    }

    return 0;
}