
#include <stdio.h>

int main(void) {
    int n;
    int values[] = {1000, 900, 500, 400, 100, 90,
                    50, 40, 10, 9, 5, 4, 1};
    char *symbols[] = {"M", "CM", "D", "CD", "C", "XC",
                       "L", "XL", "X", "IX", "V", "IV", "I"};

    printf("Enter a number (1-3999): ");
    scanf("%d", &n);

    if (n < 1 || n > 3999) {
        printf("Invalid number\n");
        return 0;
    }

    for (int i = 0; i < 13; i++) {
        while (n >= values[i]) {
            printf("%s", symbols[i]);
            n -= values[i];
        }
    }

    printf("\n");
    return 0;
}