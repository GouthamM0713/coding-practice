#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
    char bin[100];
    double result = 0, place = 0.5;
    int point = 0;

    printf("Enter binary fraction: ");
    scanf("%99s", bin);

    for (int i = 0; bin[i] != '\0'; i++) {
        if (bin[i] == '.') {
            point = 1;
            continue;
        }

        if (bin[i] != '0' && bin[i] != '1') {
            printf("Invalid binary number\n");
            return 1;
        }

        if (!point)
            result = result * 2 + (bin[i] - '0');
        else {
            result += (bin[i] - '0') * place;
            place /= 2;
        }
    }

    printf("Decimal = %.8g\n", result);
    return 0;
}