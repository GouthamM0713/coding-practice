
#include <stdio.h>

int main(void) {
    double n;

    printf("Enter a fraction from 0 to 1: ");
    scanf("%lf", &n);

    if (n < 0 || n > 1) {
        printf("Enter a value between 0 and 1\n");
        return 0;
    }

    printf("Binary = 0.");

    for (int i = 0; i < 16; i++) {
        n *= 2;

        if (n >= 1) {
            printf("1");
            n -= 1;
        } else {
            printf("0");
        }

        if (n == 0)
            break;
    }

    printf("\n");
    return 0;
}