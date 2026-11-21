
number = int(input("Enter a decimal number: "))

if number < 0:
    print("Enter a non-negative number")
else:
    print("Binary:", bin(number)[2:])
    print("Octal:", oct(number)[2:])
    print("Hexadecimal:", hex(number)[2:].upper())
