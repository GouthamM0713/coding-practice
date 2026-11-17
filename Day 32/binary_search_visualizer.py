def binary_search(arr, target):
    low = 0
    high = len(arr) - 1
    step = 1

    while low <= high:
        mid = (low + high) // 2

        print(f"\nStep {step}")
        print("Low:", low, "High:", high)
        print("Middle index:", mid)
        print("Middle value:", arr[mid])

        if arr[mid] == target:
            return mid

        elif arr[mid] < target:
            low = mid + 1

        else:
            high = mid - 1

        step += 1

    return -1


numbers = list(map(int, input("Enter sorted numbers: ").split()))
target = int(input("Enter target: "))

result = binary_search(numbers, target)

if result != -1:
    print("\nElement found at index:", result)
else:
    print("\nElement not found!")
    