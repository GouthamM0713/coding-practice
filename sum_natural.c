#include <stdio.h>

int main(void) {
    int n;
    long long sum = 0;

    printf("Enter a positive number: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Enter a positive number\n");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    printf("Sum = %lld\n", sum);

    return 0;
}
