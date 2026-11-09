grid = []

print("Enter Sudoku grid (9 rows):")

for i in range(9):
    row = list(map(int, input().split()))
    grid.append(row)

valid = True

for i in range(9):
    if len(set(grid[i])) != 9:
        valid = False

    column = [grid[j][i] for j in range(9)]

    if len(set(column)) != 9:
        valid = False

for r in range(0, 9, 3):
    for c in range(0, 9, 3):
        block = []

        for i in range(r, r + 3):
            for j in range(c, c + 3):
                block.append(grid[i][j])

        if len(set(block)) != 9:
            valid = False

if valid:
    print("Valid Sudoku")
else:
    print("Invalid Sudoku")