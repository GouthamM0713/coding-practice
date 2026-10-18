#include <stdio.h>

int main() {
    int n, temp, digit, i;
    int sum = 0, fact;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Not a strong number\n");
        return 0;
    }

    temp = n;

    do {
        digit = temp % 10;
        fact = 1;

        for (i = 1; i <= digit; i++)
            fact *= i;

        sum += fact;
        temp /= 10;
    } while (temp != 0);

    if (sum == n)
        printf("Strong number\n");
    else
        printf("Not a strong number\n");

    return 0;
}