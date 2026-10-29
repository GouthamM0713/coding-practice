#include <stdio.h>

int main(void) {
    int a[100], b[100];
    int n, m, i, j, k;

    printf("Enter sizes of two arrays: ");
    if (scanf("%d %d", &n, &m) != 2 ||
        n < 1 || n > 100 || m < 1 || m > 100)
        return 1;

    printf("Enter first array: ");
    for (i = 0; i < n; i++)
        if (scanf("%d", &a[i]) != 1)
            return 1;

    printf("Enter second array: ");
    for (i = 0; i < m; i++)
        if (scanf("%d", &b[i]) != 1)
            return 1;

    printf("Intersection: ");

    for (i = 0; i < n; i++) {
        for (k = 0; k < i; k++) {
            if (a[k] == a[i])
                break;
        }

        if (k < i)
            continue;

        for (j = 0; j < m; j++) {
            if (a[i] == b[j])
                break;
        }

        if (j < m)
            printf("%d ", a[i]);
    }

    printf("\n");
    return 0;
}