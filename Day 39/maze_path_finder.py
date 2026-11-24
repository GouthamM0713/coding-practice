from collections import deque


def solve_maze(maze):
    rows = len(maze)
    cols = len(maze[0])

    start = (0, 0)
    end = (rows - 1, cols - 1)

    queue = deque([(start, [start])])
    visited = {start}

    directions = [
        (0, 1), (1, 0),
        (0, -1), (-1, 0)
    ]

    while queue:
        (r, c), path = queue.popleft()

        if (r, c) == end:
            return path

        for dr, dc in directions:
            nr, nc = r + dr, c + dc

            if (
                0 <= nr < rows
                and 0 <= nc < cols
                and maze[nr][nc] == 0
                and (nr, nc) not in visited
            ):
                visited.add((nr, nc))
                queue.append(((nr, nc), path + [(nr, nc)]))

    return None


maze = [
    [0, 0, 1, 0, 0],
    [1, 0, 1, 0, 1],
    [0, 0, 0, 0, 0],
    [0, 1, 1, 1, 0],
    [0, 0, 0, 0, 0]
]

path = solve_maze(maze)

if path:
    print("Path found:")

    for position in path:
        print(position)

    print("Total steps:", len(path) - 1)
else:
    print("No path exists.")