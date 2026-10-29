#include <stdio.h>

#define N 20
#define INF 1000000000

int main(void) {
    int n, graph[N][N], dist[N], visited[N] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 1 || n > N) return 1;

    printf("Enter weight matrix (0 means no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] < 0) {
                printf("Negative weights are not allowed\n");
                return 1;
            }
        }

    int source;
    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    if (source < 0 || source >= n) return 1;

    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[source] = 0;

    for (int step = 0; step < n; step++) {
        int u = -1;

        for (int i = 0; i < n; i++)
            if (!visited[i] &&
                (u == -1 || dist[i] < dist[u]))
                u = i;

        if (u == -1 || dist[u] == INF) break;

        visited[u] = 1;

        for (int v = 0; v < n; v++)
            if (graph[u][v] > 0 && !visited[v] &&
                dist[u] <= INF - graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Shortest distances:\n");
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("%d -> unreachable\n", i);
        else
            printf("%d -> %d\n", i, dist[i]);
    }

    return 0;
}