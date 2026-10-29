#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 200

int precedence(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/' || c == '%')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

int main(void) {
    char infix[MAX], reversed[MAX];
    char postfix[MAX], stack[MAX];
    int i, j = 0, top = -1, n;

    printf("Enter infix expression without spaces: ");

    if (scanf("%199s", infix) != 1)
        return 1;

    n = (int)strlen(infix);

    for (i = 0; i < n; i++) {
        char c = infix[n - 1 - i];

        if (c == '(')
            reversed[i] = ')';
        else if (c == ')')
            reversed[i] = '(';
        else
            reversed[i] = c;
    }

    reversed[n] = '\0';

    for (i = 0; reversed[i] != '\0'; i++) {
        char c = reversed[i];

        if (isalnum((unsigned char)c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top >= 0 && stack[top] != '(')
                postfix[j++] = stack[top--];

            if (top < 0) {
                printf("Mismatched parentheses.\n");
                return 1;
            }

            top--;
        } else if (strchr("+-*/%^", c) != NULL) {
            while (top >= 0 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(c) ||
                    (precedence(stack[top]) == precedence(c)
                     && c == '^'))) {
                postfix[j++] = stack[top--];
            }

            stack[++top] = c;
        } else {
            printf("Unsupported character.\n");
            return 1;
        }
    }

    while (top >= 0) {
        if (stack[top] == '(') {
            printf("Mismatched parentheses.\n");
            return 1;
        }

        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';

    for (i = 0; i < j / 2; i++) {
        char temp = postfix[i];
        postfix[i] = postfix[j - 1 - i];
        postfix[j - 1 - i] = temp;
    }

    printf("Prefix expression: %s\n", postfix);

    return 0;
}