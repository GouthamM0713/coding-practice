#include <stdio.h>

int n, maze[10][10], path[10][10];

int solve(int r, int c) {
    if (r >= n || c >= n || maze[r][c] == 0 ||
        path[r][c] == 1)
        return 0;

    path[r][c] = 1;

    if (r == n - 1 && c == n - 1)
        return 1;

    if (solve(r + 1, c) || solve(r, c + 1))
        return 1;

    path[r][c] = 0;
    return 0;
}

int main(void) {
    scanf("%d", &n);

    if (n < 1 || n > 10) return 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &maze[i][j]);

    if (solve(0, 0)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf("%d ", path[i][j]);
            printf("\n");
        }
    } else {
        printf("No path found\n");
    }

    return 0;
}