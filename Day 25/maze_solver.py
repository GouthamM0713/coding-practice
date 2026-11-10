maze = [
    [0, 0, 1, 0, 0],
    [1, 0, 1, 0, 1],
    [0, 0, 0, 0, 0],
    [0, 1, 1, 1, 0],
    [0, 0, 0, 0, 0]
]

n = len(maze)
path = []


def solve(row, col):
    if row == n - 1 and col == n - 1:
        path.append((row, col))
        return True

    if row < 0 or col < 0 or row >= n or col >= n:
        return False

    if maze[row][col] == 1:
        return False

    if maze[row][col] == 2:
        return False

    maze[row][col] = 2
    path.append((row, col))

    moves = [
        (0, 1),
        (1, 0),
        (0, -1),
        (-1, 0)
    ]

    for dr, dc in moves:
        if solve(row + dr, col + dc):
            return True

    path.pop()
    maze[row][col] = 0

    return False


if solve(0, 0):
    print("Maze solved!")
    print("Path:", path)
else:
    print("No path found.")