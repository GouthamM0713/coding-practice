#include <stdio.h>
#include <ctype.h>

int main(void) {
    char s[300];
    int i = 0;

    printf("Enter encoded text (example: a3b2c1): ");

    if (scanf("%299s", s) != 1)
        return 1;

    while (s[i] != '\0') {
        char ch = s[i++];
        int count = 0;

        if (isdigit((unsigned char)ch)) {
            printf("Invalid format.\n");
            return 1;
        }

        if (s[i] == '\0' ||
            !isdigit((unsigned char)s[i])) {
            printf("Invalid format.\n");
            return 1;
        }

        while (s[i] != '\0' &&
               isdigit((unsigned char)s[i])) {
            if (count > 10000) {
                printf("Repeat count too large.\n");
                return 1;
            }

            count = count * 10 + (s[i] - '0');
            i++;
        }

        if (count > 10000) {
            printf("Repeat count too large.\n");
            return 1;
        }

        while (count > 0) {
            putchar(ch);
            count--;
        }
    }

    printf("\n");
    return 0;
}