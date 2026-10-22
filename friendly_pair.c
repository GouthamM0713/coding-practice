#include <stdio.h>

long long divisorSum(int n) {
    long long sum = 0;
    int i;

    for (i = 1; i <= n; i++) {
        if (n % i == 0)
            sum += i;
    }

    return sum;
}

int main() {
    int a, b;
    long long sumA, sumB;

    printf("Enter two positive numbers: ");
    scanf("%d %d", &a, &b);

    if (a <= 0 || b <= 0) {
        printf("Invalid input");
        return 0;
    }

    sumA = divisorSum(a);
    sumB = divisorSum(b);

    if (sumA * b == sumB * a)
        printf("Friendly Pair\n");
    else
        printf("Not a Friendly Pair\n");

    return 0;
}