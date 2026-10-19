#include <stdio.h>

int main() {
    char a[200], b[200];
    int i = 0;

    printf("Enter first string: ");
    fgets(a, sizeof(a), stdin);

    printf("Enter second string: ");
    fgets(b, sizeof(b), stdin);

    while (a[i] != '\0' && a[i] != '\n' &&
           b[i] != '\0' && b[i] != '\n' &&
           a[i] == b[i]) {
        i++;
    }

    if ((a[i] == '\n' || a[i] == '\0') &&
        (b[i] == '\n' || b[i] == '\0'))
        printf("Strings are equal\n");
    else if ((unsigned char)a[i] < (unsigned char)b[i])
        printf("First string is smaller\n");
    else
        printf("First string is greater\n");

    return 0;
}