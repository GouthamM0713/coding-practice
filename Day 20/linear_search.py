numbers = [12, 25, 38, 47, 56, 69]

target = int(input("Enter number to search: "))

found = False

for i in range(len(numbers)):
    if numbers[i] == target:
        print("Element found at position:", i + 1)
        found = True
        break

if not found:
    print("Element not found")