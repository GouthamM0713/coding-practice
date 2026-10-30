#include <stdio.h>

int binarySearch(int a[], int l, int r, int key) {
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (a[mid] == key) return mid;

        if (a[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}

int main() {
    int n, a[100], key;

    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &key);

    int bound = 1;

    while (bound < n && a[bound] < key)
        bound *= 2;

    int result = binarySearch(
        a, bound / 2,
        bound < n ? bound : n - 1, key);

    if (result == -1)
        printf("Element not found");
    else
        printf("Found at index %d", result);

    return 0;
}