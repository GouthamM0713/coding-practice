#include <stdio.h>

int n, graph[20][20], path[20];

int safe(int v, int pos) {
    if (!graph[path[pos - 1]][v])
        return 0;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;

    return 1;
}

int solve(int pos) {
    if (pos == n)
        return graph[path[pos - 1]][path[0]];

    for (int v = 1; v < n; v++) {
        if (safe(v, pos)) {
            path[pos] = v;

            if (solve(pos + 1))
                return 1;

            path[pos] = -1;
        }
    }

    return 0;
}

int main() {
    scanf("%d", &n);

    if (n < 3 || n > 20) return 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++)
        path[i] = -1;

    path[0] = 0;

    if (solve(1)) {
        printf("Hamiltonian Cycle: ");

        for (int i = 0; i < n; i++)
            printf("%d ", path[i]);

        printf("0\n");
    } else {
        printf("No Hamiltonian Cycle");
    }

    return 0;
}