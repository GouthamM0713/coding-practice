
#include <stdio.h>
#include <string.h>

int value(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int main(void) {
    char roman[100];
    int total = 0;

    printf("Enter a Roman numeral: ");
    scanf("%99s", roman);

    for (int i = 0; roman[i] != '\0'; i++) {
        int current = value(roman[i]);
        int next = value(roman[i + 1]);

        if (current == 0) {
            printf("Invalid character\n");
            return 0;
        }

        if (current < next)
            total -= current;
        else
            total += current;
    }

    printf("Decimal value = %d\n", total);
    return 0;
}