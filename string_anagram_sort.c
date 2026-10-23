#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sortCharacters(char s[]) {
    int i, j;
    char temp;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i + 1; s[j] != '\0'; j++) {
            if (s[i] > s[j]) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main(void) {
    char a[200], b[200];
    int i;

    printf("Enter first word: ");
    if (scanf("%199s", a) != 1)
        return 1;

    printf("Enter second word: ");
    if (scanf("%199s", b) != 1)
        return 1;

    if (strlen(a) != strlen(b)) {
        printf("Not anagrams.\n");
        return 0;
    }

    for (i = 0; a[i] != '\0'; i++)
        a[i] = (char)tolower((unsigned char)a[i]);

    for (i = 0; b[i] != '\0'; i++)
        b[i] = (char)tolower((unsigned char)b[i]);

    sortCharacters(a);
    sortCharacters(b);

    if (strcmp(a, b) == 0)
        printf("The words are anagrams.\n");
    else
        printf("The words are not anagrams.\n");

    return 0;
}