#include <stdio.h>

int digitSum(int n) {
    if (n == 0)
        return 0;

    return n % 10 + digitSum(n / 10);
}

int main() {
    int n;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    if (n < 0)
        printf("Invalid input");
    else
        printf("Digit sum = %d", digitSum(n));

    return 0;
}