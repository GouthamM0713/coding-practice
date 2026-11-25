import random
import time
import os


ROWS = 10
COLS = 20


def create_grid():
    return [
        [random.randint(0, 1) for _ in range(COLS)]
        for _ in range(ROWS)
    ]


def count_neighbors(grid, row, col):
    count = 0

    for dr in (-1, 0, 1):
        for dc in (-1, 0, 1):

            if dr == 0 and dc == 0:
                continue

            nr = row + dr
            nc = col + dc

            if (
                0 <= nr < ROWS
                and 0 <= nc < COLS
            ):
                count += grid[nr][nc]

    return count


def next_generation(grid):
    new_grid = [
        [0] * COLS
        for _ in range(ROWS)
    ]

    for row in range(ROWS):
        for col in range(COLS):

            neighbors = count_neighbors(
                grid, row, col
            )

            if grid[row][col] == 1:

                if neighbors in (2, 3):
                    new_grid[row][col] = 1

            elif neighbors == 3:
                new_grid[row][col] = 1

    return new_grid


def display(grid):
    for row in grid:
        print(
            "".join(
                "■ " if cell else ". "
                for cell in row
            )
        )


grid = create_grid()

generations = int(input("Enter number of generations: "))

if generations < 0:
    print("Enter a non-negative number.")

else:
    for generation in range(generations):

        os.system("cls" if os.name == "nt" else "clear")

        print("Generation:", generation + 1)

        display(grid)

        grid = next_generation(grid)

        time.sleep(0.5)

    print("\nFinal Generation:")
    display(grid)