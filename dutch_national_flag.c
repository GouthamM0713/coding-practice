#include <stdio.h>

int main(void) {
    int a[100], n;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) return 1;

    printf("Enter only 0, 1, or 2: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < 0 || a[i] > 2) {
            printf("Invalid element\n");
            return 1;
        }
    }

    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (a[mid] == 0) {
            int t = a[low];
            a[low++] = a[mid];
            a[mid++] = t;
        } else if (a[mid] == 1) {
            mid++;
        } else {
            int t = a[mid];
            a[mid] = a[high];
            a[high--] = t;
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
    return 0;
}