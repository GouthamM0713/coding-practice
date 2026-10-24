#include <stdio.h>

int main(void) {
    int n, i, j;
    int prime[10001];

    printf("Enter limit (2-10000): ");
    if (scanf("%d", &n) != 1 || n < 2 || n > 10000)
        return 1;

    for (i = 0; i <= n; i++)
        prime[i] = 1;

    prime[0] = prime[1] = 0;

    for (i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (j = i * i; j <= n; j += i)
                prime[j] = 0;
        }
    }

    printf("Prime numbers: ");
    for (i = 2; i <= n; i++) {
        if (prime[i])
            printf("%d ", i);
    }

    printf("\n");
    return 0;
}