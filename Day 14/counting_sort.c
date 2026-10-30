#include <stdio.h>

int main() {
    int n, a[100], count[1001] = {0};

    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < 0 || a[i] > 1000) return 0;
        count[a[i]]++;
    }

    printf("Sorted array: ");
    for (int i = 0; i <= 1000; i++)
        while (count[i]--)
            printf("%d ", i);

    return 0;
}