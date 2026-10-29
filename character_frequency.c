#include <stdio.h>
#include <ctype.h>

int main(void) {
    char str[] = "Programming";
    int freq[26] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower((unsigned char)str[i]);

        if (ch >= 'a' && ch <= 'z')
            freq[ch - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0)
            printf("%c = %d\n", 'a' + i, freq[i]);
    }

    return 0;
}
