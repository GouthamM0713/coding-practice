#include <stdio.h>

int bit[1001], n;

void update(int i, int value) {
    while (i <= n) {
        bit[i] += value;
        i += i & -i;
    }
}

int sum(int i) {
    int result = 0;

    while (i > 0) {
        result += bit[i];
        i -= i & -i;
    }

    return result;
}

int main() {
    int x, l, r;

    scanf("%d", &n);
    if (n < 1 || n > 1000) return 0;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        update(i, x);
    }

    scanf("%d%d", &l, &r);

    if (l < 1 || r > n || l > r) return 0;

    printf("Range Sum = %d", sum(r) - sum(l - 1));

    return 0;
}