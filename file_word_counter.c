#include <stdio.h>
#include <ctype.h>

int main(void) {
    FILE *fp;
    int ch, words = 0, inWord = 0;

    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Cannot open input.txt\n");
        printf("Create input.txt in the same folder.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (isspace((unsigned char)ch)) {
            inWord = 0;
        } else if (!inWord) {
            words++;
            inWord = 1;
        }
    }

    fclose(fp);

    printf("Total words = %d\n", words);

    return 0;
}
