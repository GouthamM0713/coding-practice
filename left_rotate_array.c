#include <stdio.h>

int main() {
    int a[100], n, rotations, i, temp;

    printf("Enter number of elements (1-100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
        return 0;

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter left rotations: ");
    scanf("%d", &rotations);

    rotations = ((rotations % n) + n) % n;

    while (rotations--) {
        temp = a[0];

        for (i = 0; i < n - 1; i++)
            a[i] = a[i + 1];

        a[n - 1] = temp;
    }

    printf("Rotated array: ");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}