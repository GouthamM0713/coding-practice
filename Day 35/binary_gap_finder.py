
number = int(input("Enter a positive integer: "))

if number <= 0:
    print("Enter a positive integer")
else:
    binary = bin(number)[2:]
    gaps = binary.strip("0").split("1")
    longest = max([len(gap) for gap in gaps], default=0)

    print("Binary:", binary)
    print("Longest binary gap:", longest)
