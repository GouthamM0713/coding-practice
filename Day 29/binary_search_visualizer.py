def binary_search(numbers, target):
    low = 0
    high = len(numbers) - 1
    step = 1

    while low <= high:
        mid = (low + high) // 2

        print(f"\nStep {step}")
        print("Current range:", numbers[low:high + 1])
        print("Middle value:", numbers[mid])

        if numbers[mid] == target:
            return mid

        elif numbers[mid] < target:
            print("Searching the right half...")
            low = mid + 1

        else:
            print("Searching the left half...")
            high = mid - 1

        step += 1

    return -1


numbers = list(map(
    int,
    input("Enter sorted numbers separated by spaces: ").split()
))

target = int(input("Enter target number: "))

if numbers != sorted(numbers):
    print("Please enter numbers in sorted order!")
else:
    result = binary_search(numbers, target)

    if result != -1:
        print(f"\nFound {target} at index {result}.")
    else:
        print("\nElement not found!")