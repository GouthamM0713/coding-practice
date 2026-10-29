#include <stdio.h>

int main(void) {
    int a[10][10];
    int rows, cols, i, j;
    int top, bottom, left, right;

    printf("Enter rows and columns (1-10): ");
    if (scanf("%d %d", &rows, &cols) != 2 ||
        rows < 1 || rows > 10 ||
        cols < 1 || cols > 10)
        return 1;

    printf("Enter matrix elements:\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (scanf("%d", &a[i][j]) != 1)
                return 1;
        }
    }

    top = 0;
    bottom = rows - 1;
    left = 0;
    right = cols - 1;

    printf("Spiral traversal: ");

    while (top <= bottom && left <= right) {
        for (j = left; j <= right; j++)
            printf("%d ", a[top][j]);
        top++;

        for (i = top; i <= bottom; i++)
            printf("%d ", a[i][right]);
        right--;

        if (top <= bottom) {
            for (j = right; j >= left; j--)
                printf("%d ", a[bottom][j]);
            bottom--;
        }

        if (left <= right) {
            for (i = bottom; i >= top; i--)
                printf("%d ", a[i][left]);
            left++;
        }
    }

    printf("\n");
    return 0;
}