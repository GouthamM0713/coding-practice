from collections import deque

maze = [
    [0, 0, 1, 0, 0],
    [1, 0, 1, 0, 1],
    [0, 0, 0, 0, 0],
    [0, 1, 1, 1, 0],
    [0, 0, 0, 0, 0]
]

start = (0, 0)
end = (4, 4)

queue = deque([(start, [start])])
visited = {start}

directions = [
    (0, 1), (1, 0),
    (0, -1), (-1, 0)
]

path = None

while queue:
    current, route = queue.popleft()

    if current == end:
        path = route
        break

    row, col = current

    for dr, dc in directions:
        nr, nc = row + dr, col + dc
        next_cell = (nr, nc)

        if (
            0 <= nr < len(maze)
            and 0 <= nc < len(maze[0])
            and maze[nr][nc] == 0
            and next_cell not in visited
        ):
            visited.add(next_cell)
            queue.append((next_cell, route + [next_cell]))

if path:
    print("Path found:")
    print(path)
    print("Steps:", len(path) - 1)
else:
    print("No path exists!")