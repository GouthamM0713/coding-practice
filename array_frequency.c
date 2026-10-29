#include <stdio.h>

int main() {
    int a[100], visited[100] = {0};
    int n, i, j, count;

    printf("Enter number of elements (1-100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
        return 0;

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n; i++) {
        if (visited[i])
            continue;

        count = 1;

        for (j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                count++;
                visited[j] = 1;
            }
        }

        printf("%d occurs %d time(s)\n", a[i], count);
    }

    return 0;
}