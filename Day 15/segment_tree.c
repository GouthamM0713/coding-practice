#include <stdio.h>

int tree[4000], a[1000];

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
        return;
    }

    int mid = (start + end) / 2;

    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, end);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l)
        return 0;

    if (l <= start && end <= r)
        return tree[node];

    int mid = (start + end) / 2;

    return query(node * 2, start, mid, l, r) +
           query(node * 2 + 1, mid + 1, end, l, r);
}

int main() {
    int n, l, r;

    scanf("%d", &n);
    if (n < 1 || n > 1000) return 0;

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    build(1, 0, n - 1);

    scanf("%d%d", &l, &r);

    if (l < 0 || r >= n || l > r) return 0;

    printf("Range Sum = %d",
           query(1, 0, n - 1, l, r));

    return 0;
}