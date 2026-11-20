
number = int(input("Enter a number (1-3999): "))

values = [
    1000, 900, 500, 400, 100, 90,
    50, 40, 10, 9, 5, 4, 1
]

symbols = [
    "M", "CM", "D", "CD", "C", "XC",
    "L", "XL", "X", "IX", "V", "IV", "I"
]

if not 1 <= number <= 3999:
    print("Invalid number")
else:
    result = ""

    for value, symbol in zip(values, symbols):
        while number >= value:
            result += symbol
            number -= value

    print("Roman numeral:", result)
