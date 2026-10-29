#include <stdio.h>

int main(void) {
    int n, sum, digit;

    printf("Enter a positive number: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Enter a positive number.\n");
        return 0;
    }

    while (n != 1 && n != 4) {
        sum = 0;

        while (n > 0) {
            digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        n = sum;
    }

    if (n == 1)
        printf("Happy Number\n");
    else
        printf("Not a Happy Number\n");

    return 0;
}
