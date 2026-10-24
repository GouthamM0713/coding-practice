#include <stdio.h>

int main(void) {
    int n;
    int count = 0;

    printf("Enter an integer: ");
    scanf("%d", &n);

    long long temp = n;

    if (temp < 0) {
        temp = -temp;
    }

    do {
        count++;
        temp /= 10;
    } while (temp != 0);

    printf("Number of digits = %d\n", count);

    return 0;
}
