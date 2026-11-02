#include <stdio.h>

int parent[100], rankSet[100];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;

    if (rankSet[a] < rankSet[b]) {
        parent[a] = b;
    } else if (rankSet[a] > rankSet[b]) {
        parent[b] = a;
    } else {
        parent[b] = a;
        rankSet[a]++;
    }
}

int main() {
    int n, m, a, b;

    scanf("%d%d", &n, &m);

    if (n < 1 || n > 100 || m < 0 || m > 1000)
        return 0;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);

        if (a < 0 || a >= n || b < 0 || b >= n)
            return 0;

        unite(a, b);
    }

    printf("Connected Components:\n");

    for (int i = 0; i < n; i++)
        printf("%d -> %d\n", i, find(i));

    return 0;
}