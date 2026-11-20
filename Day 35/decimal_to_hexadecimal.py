
number = int(input("Enter a decimal number: "))

if number < 0:
    print("Please enter a non-negative number")
else:
    print("Hexadecimal:", hex(number).upper())
