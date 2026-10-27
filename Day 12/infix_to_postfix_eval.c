#include <stdio.h>
#include <ctype.h>
#include <string.h>

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

int main(void) {
    char in[100], post[100], st[100];
    int top = -1, k = 0;

    printf("Enter expression: ");
    scanf("%99s", in);

    for (int i = 0; in[i]; i++) {
        char c = in[i];

        if (isdigit((unsigned char)c))
            post[k++] = c;
        else if (c == '(')
            st[++top] = c;
        else if (c == ')') {
            while (top >= 0 && st[top] != '(')
                post[k++] = st[top--];

            if (top < 0) {
                printf("Invalid expression\n");
                return 1;
            }
            top--;
        } else if (precedence(c)) {
            while (top >= 0 && precedence(st[top]) >= precedence(c))
                post[k++] = st[top--];

            st[++top] = c;
        } else {
            printf("Invalid character\n");
            return 1;
        }
    }

    while (top >= 0) {
        if (st[top] == '(') {
            printf("Invalid expression\n");
            return 1;
        }
        post[k++] = st[top--];
    }
    post[k] = '\0';

    int values[100], vtop = -1;

    for (int i = 0; post[i]; i++) {
        char c = post[i];

        if (isdigit((unsigned char)c))
            values[++vtop] = c - '0';
        else {
            if (vtop < 1) {
                printf("Invalid expression\n");
                return 1;
            }

            int b = values[vtop--];
            int a = values[vtop--];

            switch (c) {
                case '+': values[++vtop] = a + b; break;
                case '-': values[++vtop] = a - b; break;
                case '*': values[++vtop] = a * b; break;
                case '/':
                    if (b == 0) {
                        printf("Division by zero\n");
                        return 1;
                    }
                    values[++vtop] = a / b;
                    break;
            }
        }
    }

    if (vtop != 0) {
        printf("Invalid expression\n");
        return 1;
    }

    printf("Postfix: %s\n", post);
    printf("Result: %d\n", values[0]);
    return 0;
}