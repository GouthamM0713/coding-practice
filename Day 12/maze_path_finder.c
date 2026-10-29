#include <stdio.h>

#define N 10

int maze[N][N], path[N][N], n;

int solve(int r, int c) {
    if (r < 0 || c < 0 || r >= n || c >= n)
        return 0;

    if (maze[r][c] == 0 || path[r][c] == 1)
        return 0;

    path[r][c] = 1;

    if (r == n - 1 && c == n - 1)
        return 1;

    if (solve(r + 1, c) ||
        solve(r, c + 1) ||
        solve(r - 1, c) ||
        solve(r, c - 1))
        return 1;

    path[r][c] = 0;
    return 0;
}

int main(void) {
    printf("Enter maze size (1-10): ");

    if (scanf("%d", &n) != 1 || n < 1 || n > N) {
        printf("Invalid size\n");
        return 1;
    }

    printf("Enter maze (1=open, 0=blocked):\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &maze[i][j]) != 1 ||
                (maze[i][j] != 0 && maze[i][j] != 1)) {
                printf("Invalid maze\n");
                return 1;
            }
        }
    }

    if (solve(0, 0)) {
        printf("Path found:\n");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf("%d ", path[i][j]);

            printf("\n");
        }
    } else {
        printf("No path exists\n");
    }

    return 0;
}