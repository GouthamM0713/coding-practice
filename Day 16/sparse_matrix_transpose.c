#include <stdio.h>

int main() {
    int a[10][10], t[100][3];
    int r, c, k = 1;

    scanf("%d%d", &r, &c);

    if (r < 1 || r > 10 || c < 1 || c > 10)
        return 0;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);

            if (a[i][j] != 0) {
                t[k][0] = j;
                t[k][1] = i;
                t[k][2] = a[i][j];
                k++;
            }
        }

    t[0][0] = c;
    t[0][1] = r;
    t[0][2] = k - 1;

    printf("Transpose in triplet form:\n");

    for (int i = 0; i < k; i++)
        printf("%d %d %d\n",
               t[i][0], t[i][1], t[i][2]);

    return 0;
}