#include <stdio.h>

int main() {
    int n, first, last;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0)
        n = -n;

    last = n % 10;
    first = n;

    while (first >= 10)
        first /= 10;

    printf("First digit = %d\n", first);
    printf("Last digit = %d\n", last);

    return 0;
}