numbers = [10, 20, 30, 40, 50]

k = int(input("Enter rotation count: "))

k = k % len(numbers)

rotated = numbers[-k:] + numbers[:-k] if k else numbers

print("Rotated List:", rotated)