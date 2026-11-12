def integer_to_roman(number):
    values = [
        (1000, "M"), (900, "CM"), (500, "D"),
        (400, "CD"), (100, "C"), (90, "XC"),
        (50, "L"), (40, "XL"), (10, "X"),
        (9, "IX"), (5, "V"), (4, "IV"), (1, "I")
    ]

    result = ""

    for value, symbol in values:
        while number >= value:
            result += symbol
            number -= value

    return result


try:
    number = int(input("Enter a number (1-3999): "))

    if 1 <= number <= 3999:
        print("Roman numeral:", integer_to_roman(number))
    else:
        print("Please enter a number between 1 and 3999.")

except ValueError:
    print("Please enter a valid integer.")