numbers = list(map(
    int,
    input("Enter sorted numbers separated by spaces: ").split()
))

target = int(input("Enter number to search: "))

left = 0
right = len(numbers) - 1
steps = 0

while left <= right:
    middle = (left + right) // 2
    steps += 1

    print("Step", steps, "- Checking index:", middle)

    if numbers[middle] == target:
        print("Element found at index:", middle)
        break

    elif numbers[middle] < target:
        left = middle + 1

    else:
        right = middle - 1

else:
    print("Element not found.")

print("Total search steps:", steps)