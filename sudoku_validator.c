#include <stdio.h>

int main(void) {
    int a[9][9], valid = 1;

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < 9; i++) {
        int row[10] = {0}, col[10] = {0};

        for (int j = 0; j < 9; j++) {
            int x = a[i][j];
            int y = a[j][i];

            if (x < 1 || x > 9 || row[x])
                valid = 0;
            else
                row[x] = 1;

            if (y < 1 || y > 9 || col[y])
                valid = 0;
            else
                col[y] = 1;
        }
    }

    for (int r = 0; r < 9; r += 3)
        for (int c = 0; c < 9; c += 3) {
            int seen[10] = {0};

            for (int i = r; i < r + 3; i++)
                for (int j = c; j < c + 3; j++) {
                    int x = a[i][j];

                    if (x < 1 || x > 9 || seen[x])
                        valid = 0;
                    else
                        seen[x] = 1;
                }
        }

    printf("%s\n", valid ? "Valid Sudoku" : "Invalid Sudoku");
    return 0;
}