binary = input("Enter a binary number: ")

decimal = 0
power = 0

for digit in binary[::-1]:
    if digit not in "01":
        print("Invalid binary number")
        break
    decimal += int(digit) * (2 ** power)
    power += 1
else:
    print("Decimal:", decimal)