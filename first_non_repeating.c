#include <stdio.h>

int main(void) {
    char str[500];
    int freq[256] = {0};

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++)
        freq[(unsigned char)str[i]]++;

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)str[i];

        if (ch != '\n' && freq[ch] == 1) {
            printf("First non-repeating character: %c\n", ch);
            return 0;
        }
    }

    printf("No non-repeating character found.\n");

    return 0;
}
