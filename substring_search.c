#include <stdio.h>
#include <string.h>

int main(void) {
    char text[] = "I love programming";
    char pattern[] = "programming";

    if (strstr(text, pattern) != NULL)
        printf("Substring found");
    else
        printf("Substring not found");

    return 0;
}
