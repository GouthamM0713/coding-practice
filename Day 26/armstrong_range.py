try:
    start = int(input("Enter starting number: "))
    end = int(input("Enter ending number: "))

    if start < 0 or end < start:
        print("Invalid range!")
    else:
        print("Armstrong numbers:")

        for number in range(start, end + 1):
            digits = str(number)
            power = len(digits)

            total = sum(int(digit) ** power for digit in digits)

            if total == number:
                print(number)

except ValueError:
    print("Enter valid integers!")