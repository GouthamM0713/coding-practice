#include <stdio.h>

int main(void) {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Cube = %d\n", n * n * n);

    return 0;
}