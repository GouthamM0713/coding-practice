#include <stdio.h>

int main(void) {
    char str[] = "C programming is fun";
    int i, j = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ')
            str[j++] = str[i];
    }

    str[j] = '\0';

    printf("%s\n", str);
    return 0;
}
