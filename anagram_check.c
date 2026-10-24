#include <stdio.h>
#include <ctype.h>

int main(void) {
    char a[500], b[500];
    int freq[256] = {0};

    printf("Enter first string: ");
    fgets(a, sizeof(a), stdin);

    printf("Enter second string: ");
    fgets(b, sizeof(b), stdin);

    for (int i = 0; a[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)a[i];

        if (!isspace(ch))
            freq[tolower(ch)]++;
    }

    for (int i = 0; b[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)b[i];

        if (!isspace(ch))
            freq[tolower(ch)]--;
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            printf("Not anagrams.\n");
            return 0;
        }
    }

    printf("Anagrams.\n");

    return 0;
}
