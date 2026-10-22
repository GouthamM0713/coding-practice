#include <stdio.h>

int main() {
    FILE *fp;
    char text[300];
    int ch;

    printf("Enter text to save: ");
    fgets(text, sizeof(text), stdin);

    fp = fopen("day5_output.txt", "w");

    if (fp == NULL) {
        printf("Unable to create file\n");
        return 1;
    }

    fputs(text, fp);
    fclose(fp);

    fp = fopen("day5_output.txt", "r");

    if (fp == NULL) {
        printf("Unable to open file\n");
        return 1;
    }

    printf("\nText read from file:\n");

    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);

    fclose(fp);

    return 0;
}