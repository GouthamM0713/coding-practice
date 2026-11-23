number = abs(int(input("Enter an integer: ")))

original = number

while number >= 10:
    digit_sum = 0

    while number > 0:
        digit_sum += number % 10
        number //= 10

    number = digit_sum

print("Original number:", original)
print("Digital root:", number)