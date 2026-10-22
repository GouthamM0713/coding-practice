#include <stdio.h>

int main(void) {
    int n;

    printf("Enter the limit: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }

    printf("\n");

    return 0;
}
