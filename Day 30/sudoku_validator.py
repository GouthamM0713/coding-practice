def valid_group(numbers):
    return sorted(numbers) == list(range(1, 10))


def validate_sudoku(board):
    for row in board:
        if not valid_group(row):
            return False

    for col in range(9):
        column = [board[row][col] for row in range(9)]
        if not valid_group(column):
            return False

    for row in range(0, 9, 3):
        for col in range(0, 9, 3):
            block = []

            for i in range(row, row + 3):
                for j in range(col, col + 3):
                    block.append(board[i][j])

            if not valid_group(block):
                return False

    return True


print("Enter the completed Sudoku board.")
print("Enter 9 digits per row, without spaces.")

board = []

for i in range(9):
    while True:
        line = input(f"Row {i + 1}: ")

        if len(line) == 9 and line.isdigit():
            board.append([int(digit) for digit in line])
            break

        print("Please enter exactly 9 digits.")

if validate_sudoku(board):
    print("Valid completed Sudoku board!")
else:
    print("Invalid Sudoku board!")