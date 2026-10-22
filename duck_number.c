#include <stdio.h>

int main() {
    long long n;
    int found = 0;

    printf("Enter a positive integer: ");
    scanf("%lld", &n);

    if (n <= 0) {
        printf("Enter a positive integer");
        return 0;
    }

    while (n > 0) {
        if (n % 10 == 0) {
            found = 1;
            break;
        }
        n /= 10;
    }

    if (found)
        printf("Duck number\n");
    else
        printf("Not a Duck number\n");

    return 0;
}