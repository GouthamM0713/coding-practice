import math

number = int(input("Enter a positive integer: "))

if number < 0:
    print("Enter a non-negative integer.")
else:
    total = sum(
        math.factorial(int(digit))
        for digit in str(number)
    )

    if total == number:
        print(number, "is a Strong Number.")
    else:
        print(number, "is not a Strong Number.")

    print("Sum of factorials:", total)