def is_valid_group(group):
    numbers = [n for n in group if n != 0]
    return len(numbers) == len(set(numbers))


def validate_sudoku(board):
    for row in board:
        if not is_valid_group(row):
            return False

    for col in range(9):
        column = [board[row][col] for row in range(9)]

        if not is_valid_group(column):
            return False

    for box_row in range(0, 9, 3):
        for box_col in range(0, 9, 3):
            box = []

            for r in range(box_row, box_row + 3):
                for c in range(box_col, box_col + 3):
                    box.append(board[r][c])

            if not is_valid_group(box):
                return False

    return True


print("Enter 9 rows of Sudoku numbers.")
print("Use 0 for empty cells.")

board = []

for i in range(9):
    while True:
        row = input(f"Row {i + 1}: ")

        if len(row) == 9 and row.isdigit():
            numbers = [int(n) for n in row]

            if all(0 <= n <= 9 for n in numbers):
                board.append(numbers)
                break

        print("Enter exactly 9 digits from 0 to 9.")

if validate_sudoku(board):
    print("Sudoku board is valid!")
else:
    print("Sudoku board is invalid!")
    