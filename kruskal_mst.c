#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, w;
};

int parent[50], rankSet[50];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

int unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return 0;

    if (rankSet[a] < rankSet[b]) {
        int t = a;
        a = b;
        b = t;
    }

    parent[b] = a;

    if (rankSet[a] == rankSet[b])
        rankSet[a]++;

    return 1;
}

int compare(const void *a, const void *b) {
    const struct Edge *x = a;
    const struct Edge *y = b;
    return (x->w > y->w) - (x->w < y->w);
}

int main(void) {
    int n, m, count = 0;
    long long total = 0;
    struct Edge e[200];

    scanf("%d%d", &n, &m);

    if (n < 1 || n > 50 || m < 0 || m > 200)
        return 0;

    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);

        if (e[i].u < 0 || e[i].u >= n ||
            e[i].v < 0 || e[i].v >= n)
            return 0;
    }

    for (int i = 0; i < n; i++)
        parent[i] = i;

    qsort(e, m, sizeof(e[0]), compare);

    for (int i = 0; i < m; i++) {
        if (unite(e[i].u, e[i].v)) {
            printf("%d - %d : %d\n",
                   e[i].u, e[i].v, e[i].w);
            total += e[i].w;
            count++;
        }
    }

    if (count != n - 1)
        printf("Graph is disconnected\n");
    else
        printf("Minimum cost = %lld\n", total);

    return 0;
}