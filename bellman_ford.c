#include <stdio.h>

#define MAX 1000000000

struct Edge {
    int u, v, w;
};

int main(void) {
    int n, m, source;
    struct Edge e[200];

    scanf("%d%d", &n, &m);

    if (n < 1 || n > 50 || m < 0 || m > 200)
        return 0;

    for (int i = 0; i < m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);

    scanf("%d", &source);
    if (source < 0 || source >= n) return 0;

    int dist[50];

    for (int i = 0; i < n; i++)
        dist[i] = MAX;

    dist[source] = 0;

    for (int i = 1; i < n; i++) {
        int changed = 0;

        for (int j = 0; j < m; j++) {
            int u = e[j].u, v = e[j].v, w = e[j].w;

            if (u < 0 || u >= n || v < 0 || v >= n)
                return 0;

            if (dist[u] != MAX &&
                (long long)dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                changed = 1;
            }
        }

        if (!changed) break;
    }

    for (int j = 0; j < m; j++) {
        int u = e[j].u, v = e[j].v, w = e[j].w;

        if (dist[u] != MAX &&
            (long long)dist[u] + w < dist[v]) {
            printf("Negative weight cycle detected\n");
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == MAX)
            printf("%d: Unreachable\n", i);
        else
            printf("%d: %d\n", i, dist[i]);
    }

    return 0;
}