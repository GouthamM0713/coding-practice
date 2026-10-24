#include <stdio.h>

int main(void) {
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int top = 0, bottom = 2;
    int left = 0, right = 2;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++)
            printf("%d ", a[top][j]);
        top++;

        for (int i = top; i <= bottom; i++)
            printf("%d ", a[i][right]);
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                printf("%d ", a[bottom][j]);
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", a[i][left]);
            left++;
        }
    }

    return 0;
}
