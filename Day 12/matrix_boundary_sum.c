#include <stdio.h>

int main(void) {
    int a[20][20], r, c, sum = 0;

    printf("Enter rows and columns: ");
    if (scanf("%d%d", &r, &c) != 2 ||
        r < 1 || r > 20 || c < 1 || c > 20) {
        printf("Invalid dimensions\n");
        return 1;
    }

    printf("Enter matrix elements:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i == 0 || i == r - 1 ||
                j == 0 || j == c - 1)
                sum += a[i][j];
        }
    }

    printf("Boundary sum = %d\n", sum);
    return 0;
}