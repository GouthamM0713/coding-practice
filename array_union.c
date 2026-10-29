#include <stdio.h>

int main(void) {
    int a[200], n, m, i, j, count = 0;
    int value, duplicate;

    printf("Enter sizes of two arrays: ");
    if (scanf("%d %d", &n, &m) != 2 ||
        n < 1 || n > 100 || m < 1 || m > 100)
        return 1;

    printf("Enter first array: ");
    for (i = 0; i < n; i++) {
        if (scanf("%d", &a[count]) != 1)
            return 1;
        count++;
    }

    printf("Enter second array: ");
    for (i = 0; i < m; i++) {
        if (scanf("%d", &value) != 1)
            return 1;

        duplicate = 0;

        for (j = 0; j < count; j++) {
            if (a[j] == value) {
                duplicate = 1;
                break;
            }
        }

        if (!duplicate)
            a[count++] = value;
    }

    printf("Union: ");
    for (i = 0; i < count; i++)
        printf("%d ", a[i]);

    printf("\n");
    return 0;
}