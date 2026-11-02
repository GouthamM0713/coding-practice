#include <stdio.h>

int heap[100], n = 0;

void insert(int x) {
    if (n == 100) return;

    int i = n++;
    heap[i] = x;

    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        int t = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = t;

        i = (i - 1) / 2;
    }
}

int extractMin() {
    if (n == 0) return -1;

    int result = heap[0];
    heap[0] = heap[--n];

    int i = 0;

    while (1) {
        int smallest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && heap[l] < heap[smallest])
            smallest = l;

        if (r < n && heap[r] < heap[smallest])
            smallest = r;

        if (smallest == i) break;

        int t = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = t;

        i = smallest;
    }

    return result;
}

int main() {
    int count, x;

    scanf("%d", &count);

    if (count < 1 || count > 100) return 0;

    for (int i = 0; i < count; i++) {
        scanf("%d", &x);
        insert(x);
    }

    printf("Elements in ascending order:\n");

    while (n > 0)
        printf("%d ", extractMin());

    return 0;
}