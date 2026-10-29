#include <stdio.h>

int main(void) {
    char str[500];
    int count;

    printf("Enter a string: ");
    scanf("%499s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        count = 1;

        while (str[i] == str[i + 1]) {
            count++;
            i++;
        }

        printf("%c%d", str[i], count);
    }

    printf("\n");

    return 0;
}
