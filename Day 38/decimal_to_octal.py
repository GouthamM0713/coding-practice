number = int(input("Enter a decimal number: "))

if number < 0:
    print("Enter a non-negative number.")
else:
    octal = ""

    if number == 0:
        octal = "0"

    while number > 0:
        remainder = number % 8
        octal = str(remainder) + octal
        number //= 8

    print("Octal representation:", octal)