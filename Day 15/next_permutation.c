#include <stdio.h>

int main() {
    int n, a[100];

    scanf("%d", &n);

    if (n < 1 || n > 100) return 0;

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int i = n - 2;

    while (i >= 0 && a[i] >= a[i + 1])
        i--;

    if (i < 0) {
        printf("No next permutation");
        return 0;
    }

    int j = n - 1;

    while (a[j] <= a[i])
        j--;

    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;

    int left = i + 1, right = n - 1;

    while (left < right) {
        temp = a[left];
        a[left] = a[right];
        a[right] = temp;

        left++;
        right--;
    }

    printf("Next permutation: ");

    for (int k = 0; k < n; k++)
        printf("%d ", a[k]);

    return 0;
}