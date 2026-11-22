
roman = input("Enter a Roman numeral: ").upper()

values = {
    "I": 1, "V": 5, "X": 10,
    "L": 50, "C": 100, "D": 500, "M": 1000
}

total = 0
previous = 0
valid = True

for char in reversed(roman):
    if char not in values:
        valid = False
        break

    current = values[char]

    if current < previous:
        total -= current
    else:
        total += current

    previous = current

if valid and roman:
    print("Integer value:", total)
else:
    print("Invalid Roman numeral")
