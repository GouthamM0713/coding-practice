#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int low, high;

    printf("Enter lower and upper limits: ");
    scanf("%d %d", &low, &high);

    if (low < 0 || high < low || high > 1000000) {
        printf("Invalid range (maximum 1000000)\n");
        return 1;
    }

    int *prime = calloc(high + 1, sizeof(int));
    if (!prime) return 1;

    for (int i = 2; i <= high; i++)
        prime[i] = 1;

    for (int p = 2; p <= high / p; p++)
        if (prime[p])
            for (int j = p * p; j <= high; j += p)
                prime[j] = 0;

    printf("Primes in range: ");
    for (int i = low < 2 ? 2 : low; i <= high; i++)
        if (prime[i]) printf("%d ", i);

    printf("\n");
    free(prime);
    return 0;
}