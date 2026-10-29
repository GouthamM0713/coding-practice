#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char line[500], words[100][50];
    int count[100] = {0}, n = 0;

    printf("Enter a sentence: ");
    if (!fgets(line, sizeof(line), stdin))
        return 1;

    char *p = strtok(line, " \t\n.,!?;:");

    while (p && n < 100) {
        char temp[50];
        int len = 0;

        while (*p && len < 49)
            temp[len++] = (char)tolower((unsigned char)*p++);

        temp[len] = '\0';

        int i;
        for (i = 0; i < n; i++)
            if (strcmp(words[i], temp) == 0)
                break;

        if (i == n) {
            strcpy(words[n], temp);
            count[n] = 1;
            n++;
        } else {
            count[i]++;
        }

        p = strtok(NULL, " \t\n.,!?;:");
    }

    printf("\nWord frequencies:\n");
    for (int i = 0; i < n; i++)
        printf("%s : %d\n", words[i], count[i]);

    return 0;
}