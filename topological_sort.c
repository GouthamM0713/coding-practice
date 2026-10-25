#include <stdio.h>

int main(void) {
    int n, graph[20][20], indegree[20] = {0};
    int queue[20], front = 0, rear = 0, count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 1 || n > 20) return 1;

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] != 0 && graph[i][j] != 1)
                return 1;
            if (graph[i][j]) indegree[j]++;
        }

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    printf("Topological order: ");

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        count++;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && --indegree[v] == 0)
                queue[rear++] = v;
        }
    }

    if (count != n)
        printf("\nGraph contains a cycle; no topological order exists");

    printf("\n");
    return 0;
}