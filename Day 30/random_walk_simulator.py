import random

x = 0
y = 0
steps = 0

directions = {
    "UP": (0, 1),
    "DOWN": (0, -1),
    "LEFT": (-1, 0),
    "RIGHT": (1, 0)
}

try:
    total_steps = int(input("Enter number of steps: "))

    if total_steps <= 0:
        print("Enter a positive number!")

    else:
        print("\n--- Random Walk ---")

        for step in range(total_steps):
            direction = random.choice(list(directions.keys()))

            dx, dy = directions[direction]

            x += dx
            y += dy
            steps += 1

            print(
                f"Step {steps}: {direction} "
                f"-> Position ({x}, {y})"
            )

        distance = (x ** 2 + y ** 2) ** 0.5

        print("\n--- Final Results ---")
        print("Total steps:", steps)
        print("Final X position:", x)
        print("Final Y position:", y)
        print("Distance from starting point:", round(distance, 2))

except ValueError:
    print("Please enter a valid integer!")