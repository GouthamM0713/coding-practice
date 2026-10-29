#include <stdio.h>

int main(void) {
    int a[20][20], r, c, found = 0;

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
            int rowMin = 1, colMax = 1;

            for (int k = 0; k < c; k++)
                if (a[i][k] < a[i][j])
                    rowMin = 0;

            for (int k = 0; k < r; k++)
                if (a[k][j] > a[i][j])
                    colMax = 0;

            if (rowMin && colMax) {
                printf("Saddle point: %d at (%d, %d)\n",
                       a[i][j], i, j);
                found = 1;
            }
        }
    }

    if (!found)
        printf("No saddle point found\n");

    return 0;
}