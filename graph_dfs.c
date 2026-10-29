#include <stdio.h>

int n, a[20][20], visited[20];

void dfs(int u) {
    visited[u] = 1;
    printf("%d ", u);

    for (int v = 0; v < n; v++)
        if (a[u][v] && !visited[v])
            dfs(v);
}

int main(void) {
    int start;

    scanf("%d", &n);
    if (n < 1 || n > 20) return 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    scanf("%d", &start);

    if (start < 0 || start >= n) return 0;

    dfs(start);
    printf("\n");

    return 0;
}