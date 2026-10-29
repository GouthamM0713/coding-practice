#include <stdio.h>

int main(void) {
    int a[100], stack[100], n, top = -1;
    int result[100];

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) return 1;

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = n - 1; i >= 0; i--) {
        while (top >= 0 && stack[top] <= a[i])
            top--;

        result[i] = (top < 0) ? -1 : stack[top];
        stack[++top] = a[i];
    }

    printf("Next greater elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);

    printf("\n");
    return 0;
}