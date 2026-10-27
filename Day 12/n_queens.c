#include <stdio.h>
#include <stdlib.h>

#define MAX 15

int board[MAX], n;

int safe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col ||
            abs(board[i] - col) == abs(i - row))
            return 0;
    }

    return 1;
}

int solve(int row) {
    if (row == n)
        return 1;

    for (int col = 0; col < n; col++) {
        if (safe(row, col)) {
            board[row] = col;

            if (solve(row + 1))
                return 1;
        }
    }

    return 0;
}

int main(void) {
    printf("Enter N (1-15): ");

    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid N\n");
        return 1;
    }

    if (solve(0)) {
        printf("One solution:\n");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf("%c ", board[i] == j ? 'Q' : '.');

            printf("\n");
        }
    } else {
        printf("No solution exists\n");
    }

    return 0;
}