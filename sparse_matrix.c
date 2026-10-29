#include <stdio.h>

int main(void) {
    int a[10][10], r, c, zeros = 0;
    scanf("%d%d", &r, &c);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0) zeros++;
        }

    if (zeros > (r * c) / 2)
        printf("Sparse matrix\n");
    else
        printf("Not a sparse matrix\n");

    return 0;
}