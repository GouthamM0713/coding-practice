#include <stdio.h>

int n, m, graph[20][20], color[20];

int safe(int v, int c) {
    for (int i = 0; i < n; i++)
        if (graph[v][i] && color[i] == c)
            return 0;

    return 1;
}

int solve(int v) {
    if (v == n) return 1;

    for (int c = 1; c <= m; c++) {
        if (safe(v, c)) {
            color[v] = c;

            if (solve(v + 1))
                return 1;

            color[v] = 0;
        }
    }

    return 0;
}

int main() {
    scanf("%d%d", &n, &m);

    if (n < 1 || n > 20 || m < 1 || m > 20)
        return 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    if (solve(0)) {
        printf("Vertex Colors:\n");

        for (int i = 0; i < n; i++)
            printf("Vertex %d = Color %d\n", i, color[i]);
    } else {
        printf("Coloring not possible");
    }

    return 0;
}