#include <stdio.h>

int main(void) {
    int a[] = {2, 4, 2, 7, 4, 2};
    int n = sizeof(a) / sizeof(a[0]);
    int visited[6] = {0};

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        int count = 1;

        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                count++;
                visited[j] = 1;
            }
        }

        printf("%d occurs %d times\n", a[i], count);
    }

    return 0;
}
