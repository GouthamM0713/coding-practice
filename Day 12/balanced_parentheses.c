#include <stdio.h>
#include <string.h>

int main(void) {
    char s[500], stack[500];
    int top = -1, valid = 1;

    printf("Enter expression: ");
    if (!fgets(s, sizeof(s), stdin))
        return 1;

    for (int i = 0; s[i]; i++) {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{')
            stack[++top] = c;
        else if (c == ')' || c == ']' || c == '}') {
            if (top < 0) {
                valid = 0;
                break;
            }

            char open = stack[top--];

            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                valid = 0;
                break;
            }
        }
    }

    if (top != -1)
        valid = 0;

    printf("%s\n", valid ? "Balanced" : "Not balanced");
    return 0;
}