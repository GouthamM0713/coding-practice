def solve_n_queens(n):
    board = [-1] * n
    solutions = []

    def is_safe(row, col):
        for previous_row in range(row):
            previous_col = board[previous_row]

            if previous_col == col:
                return False

            if abs(previous_col - col) == abs(previous_row - row):
                return False

        return True

    def backtrack(row):
        if row == n:
            solutions.append(board.copy())
            return

        for col in range(n):
            if is_safe(row, col):
                board[row] = col
                backtrack(row + 1)
                board[row] = -1

    backtrack(0)

    return solutions


n = int(input("Enter chessboard size: "))

if n <= 0:
    print("Enter a positive number.")
else:
    solutions = solve_n_queens(n)

    print("Total solutions:", len(solutions))

    for solution in solutions:
        for col in solution:
            print(" ".join(
                "Q" if i == col else "."
                for i in range(n)
            ))
        print()