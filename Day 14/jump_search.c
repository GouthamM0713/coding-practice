#include <stdio.h>
#include <math.h>

int main() {
    int n, a[100], key;

    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &key);

    int step = (int)sqrt(n);
    int start = 0, end = step;

    while (start < n && a[end < n ? end : n - 1] < key) {
        start = end;
        end += step;
        if (start >= n) break;
    }

    int found = -1;

    for (int i = start; i < n && i < end; i++) {
        if (a[i] == key) {
            found = i;
            break;
        }
    }

    if (found == -1)
        printf("Element not found");
    else
        printf("Found at index %d", found);

    return 0;
}