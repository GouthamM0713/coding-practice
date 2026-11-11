def binary_search(arr, target, low, high):

    if low > high:
        return -1

    mid = (low + high) // 2

    if arr[mid] == target:
        return mid

    elif target < arr[mid]:
        return binary_search(arr, target, low, mid - 1)

    else:
        return binary_search(arr, target, mid + 1, high)


try:
    numbers = list(map(int, input(
        "Enter sorted numbers separated by spaces: "
    ).split()))

    target = int(input("Enter number to search: "))

    if not numbers or numbers != sorted(numbers):
        print("Please enter a non-empty sorted list.")
    else:
        result = binary_search(numbers, target, 0, len(numbers) - 1)

        if result == -1:
            print("Element not found.")
        else:
            print("Element found at index:", result)

except ValueError:
    print("Enter valid integers!")