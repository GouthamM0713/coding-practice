
number = int(input("Enter a positive integer: "))

if number < 2:
    print("Enter a number greater than 1")
else:
    factors = []
    divisor = 2

    while divisor * divisor <= number:
        while number % divisor == 0:
            factors.append(divisor)
            number //= divisor

        divisor += 1

    if number > 1:
        factors.append(number)

    print("Prime factors:", factors)
