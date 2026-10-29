#include <stdio.h>

int main(void) {
    int a[100], n, k, temp[100];

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid size.\n");
        return 0;
    }

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter rotations: ");
    scanf("%d", &k);

    k = ((k % n) + n) % n;

    for (int i = 0; i < n; i++)
        temp[i] = a[(i + k) % n];

    printf("Rotated array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", temp[i]);

    printf("\n");

    return 0;
}
