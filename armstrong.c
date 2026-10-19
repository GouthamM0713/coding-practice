#include <stdio.h>

int main() {
    int n, temp, digit, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Not an Armstrong number\n");
        return 0;
    }

    temp = n;

    do {
        digit = temp % 10;
        sum += digit * digit * digit;
        temp /= 10;
    } while (temp != 0);

    if (sum == n)
        printf("Armstrong number\n");
    else
        printf("Not an Armstrong number\n");

    return 0;
}