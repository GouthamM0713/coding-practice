#include <stdio.h>

int main(void) {
    int n, a[20][20], visited[20] = {0};
    int q[400], front = 0, rear = 0, start;

    scanf("%d", &n);

    if (n < 1 || n > 20) return 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    scanf("%d", &start);

    if (start < 0 || start >= n) return 0;

    q[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int u = q[front++];
        printf("%d ", u);

        for (int v = 0; v < n; v++) {
            if (a[u][v] && !visited[v]) {
                visited[v] = 1;
                q[rear++] = v;
            }
        }
    }

    printf("\n");
    return 0;
}