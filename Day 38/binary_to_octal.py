binary = input("Enter a binary number: ")

if not binary or any(bit not in "01" for bit in binary):
    print("Invalid binary number.")
else:
    decimal = int(binary, 2)
    octal = oct(decimal)[2:]

    print("Decimal:", decimal)
    print("Octal:", octal)