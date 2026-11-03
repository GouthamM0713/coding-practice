n = int(input("Enter a number: "))
temp = n
total = 0
power = len(str(n))

while temp > 0:
    digit = temp % 10
    total += digit ** power
    temp //= 10

if total == n:
    print("Armstrong Number")
else:
    print("Not Armstrong Number")