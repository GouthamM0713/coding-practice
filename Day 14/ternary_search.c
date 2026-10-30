#include <stdio.h>

int main() {
    int n, a[100], key;
    scanf("%d", &n);

    if (n < 1 || n > 100) return 0;

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &key);

    int l = 0, r = n - 1, found = -1;

    while (l <= r) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if (a[mid1] == key) {
            found = mid1;
            break;
        }

        if (a[mid2] == key) {
            found = mid2;
            break;
        }

        if (key < a[mid1])
            r = mid1 - 1;
        else if (key > a[mid2])
            l = mid2 + 1;
        else {
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }

    if (found == -1)
        printf("Element not found");
    else
        printf("Element found at index %d", found);

    return 0;
}