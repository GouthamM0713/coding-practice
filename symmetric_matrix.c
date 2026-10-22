#include <stdio.h>

int main(void) {
    int a[3][3] = {
        {1, 2, 3},
        {2, 4, 5},
        {3, 5, 6}
    };

    int symmetric = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (a[i][j] != a[j][i])
                symmetric = 0;
        }
    }

    if (symmetric)
        printf("Symmetric matrix");
    else
        printf("Not a symmetric matrix");

    return 0;
}
