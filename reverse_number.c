#include <stdio.h>

int main(void) {
    int n;
    long long reverse = 0;

    printf("Enter an integer: ");
    scanf("%d", &n);

    int temp = n;

    while (temp != 0) {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
    }

    if (n < 0) {
        reverse = -reverse;
    }

    printf("Reversed number = %lld\n", reverse);

    return 0;
}
