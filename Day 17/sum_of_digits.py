n = int(input("Enter a number: "))
total = 0

while n > 0:
    total += n % 10
    n //= 10

print("Sum of digits:", total)