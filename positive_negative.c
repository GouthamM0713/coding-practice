#include <stdio.h>

int main(void) {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Positive number\n");
    } else if (n < 0) {
        printf("Negative number\n");
    } else {
        printf("The number is zero\n");
    }

    return 0;
}
