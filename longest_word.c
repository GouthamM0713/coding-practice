#include <stdio.h>
#include <string.h>

int main(void) {
    char str[] = "C programming builds strong logic";
    char longest[100] = "";
    char *word = strtok(str, " \t\n");

    while (word != NULL) {
        if (strlen(word) > strlen(longest))
            strcpy(longest, word);

        word = strtok(NULL, " \t\n");
    }

    printf("Longest word: %s\n", longest);
    return 0;
}
