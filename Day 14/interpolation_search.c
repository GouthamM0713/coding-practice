#include <stdio.h>

int main() {
    int n, a[100], key;
    scanf("%d", &n);

    if (n < 1 || n > 100) return 0;

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &key);

    int low = 0, high = n - 1, pos = -1;

    while (low <= high &&
           key >= a[low] && key <= a[high]) {

        if (a[low] == a[high]) {
            if (a[low] == key) pos = low;
            break;
        }

        int mid = low + (int)(
            ((double)(key - a[low]) * (high - low)) /
            (a[high] - a[low]));

        if (a[mid] == key) {
            pos = mid;
            break;
        }

        if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (pos == -1)
        printf("Element not found");
    else
        printf("Element found at index %d", pos);

    return 0;
}