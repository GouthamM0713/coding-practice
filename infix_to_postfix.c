#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 500

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main(void) {
    char infix[SIZE], stack[SIZE], postfix[SIZE];
    int top = -1, j = 0;

    printf("Enter infix expression: ");
    if (scanf("%499s", infix) != 1)
        return 1;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum((unsigned char)ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top >= 0 && stack[top] != '(')
                postfix[j++] = stack[top--];

            if (top < 0) {
                printf("Invalid expression.\n");
                return 1;
            }

            top--;
        } else if (precedence(ch) > 0) {
            while (top >= 0 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(ch) ||
                   (precedence(stack[top]) == precedence(ch) &&
                    ch != '^'))) {
                postfix[j++] = stack[top--];
            }

            stack[++top] = ch;
        } else {
            printf("Unsupported character.\n");
            return 1;
        }
    }

    while (top >= 0) {
        if (stack[top] == '(') {
            printf("Invalid expression.\n");
            return 1;
        }

        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
