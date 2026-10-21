#include <stdio.h>
#include <string.h>

int main(void) {
    char str[500];
    char *words[100];
    int count = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    char *token = strtok(str, " \t\r\n");

    while (token != NULL && count < 100) {
        words[count++] = token;
        token = strtok(NULL, " \t\r\n");
    }

    printf("Reversed words: ");

    for (int i = count - 1; i >= 0; i--)
        printf("%s%s", words[i], i ? " " : "");

    printf("\n");

    return 0;
}
