#include <stdio.h>

int main(void) {
    int n, temp, sum = 0;

    printf("Enter a positive number: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Enter a positive number.\n");
        return 0;
    }

    temp = n;

    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }

    if (n % sum == 0)
        printf("%d is a Harshad Number.\n", n);
    else
        printf("%d is not a Harshad Number.\n", n);

    return 0;
}
