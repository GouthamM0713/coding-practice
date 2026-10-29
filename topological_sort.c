#include <stdio.h>

int main(void) {
    int n, a[20][20], indegree[20] = {0};
    int queue[20], front = 0, rear = 0, count = 0;

    scanf("%d", &n);
    if (n < 1 || n > 20) return 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j])
                indegree[j]++;
        }

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        count++;

        for (int v = 0; v < n; v++)
            if (a[u][v] && --indegree[v] == 0)
                queue[rear++] = v;
    }

    if (count != n)
        printf("Cycle detected");

    printf("\n");
    return 0;
}