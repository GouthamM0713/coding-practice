
start = int(input("Enter starting number: "))
end = int(input("Enter ending number: "))

if start < 1 or end < start:
    print("Invalid range")
else:
    print("Perfect numbers:")

    for number in range(start, end + 1):
        divisor_sum = 0

        for divisor in range(1, number):
            if number % divisor == 0:
                divisor_sum += divisor

        if divisor_sum == number:
            print(number)
