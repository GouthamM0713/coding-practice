n = int(input("Enter a decimal number: "))

if n == 0:
    print("Binary: 0")
else:
    binary = ""

    while n > 0:
        binary = str(n % 2) + binary
        n //= 2

    print("Binary:", binary)