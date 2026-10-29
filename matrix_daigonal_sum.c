#include <stdio.h>

int main() {
    int a[10][10], n, i, j;
    int mainSum = 0, secondarySum = 0;

    printf("Enter matrix size (1-10): ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Invalid matrix size");
        return 0;
    }

    printf("Enter matrix elements:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }

    for (i = 0; i < n; i++) {
        mainSum += a[i][i];
        secondarySum += a[i][n - 1 - i];
    }

    printf("Main diagonal sum = %d\n", mainSum);
    printf("Secondary diagonal sum = %d\n", secondarySum);

    return 0;
}