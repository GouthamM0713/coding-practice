#include <stdio.h>

int main() {
    int n, i, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (i = 1; i <= n / 2; i++) {
        if (n % i == 0)
            sum += i;
    }

    if (n > 1 && sum == n)
        printf("Perfect number\n");
    else
        printf("Not a perfect number\n");

    return 0;
}