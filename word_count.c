#include <stdio.h>
#include <ctype.h>

int main(void) {
    char str[500];
    int words = 0, inWord = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace((unsigned char)str[i])) {
            inWord = 0;
        } else if (!inWord) {
            words++;
            inWord = 1;
        }
    }

    printf("Word count = %d\n", words);

    return 0;
}
