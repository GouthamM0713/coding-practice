isbn = input("Enter 13-digit ISBN: ")

if len(isbn) == 13 and isbn.isdigit():
    total = 0

    for i in range(13):
        digit = int(isbn[i])
        total += digit * (1 if i % 2 == 0 else 3)

    if total % 10 == 0:
        print("Valid ISBN-13")
    else:
        print("Invalid ISBN-13")
else:
    print("ISBN must contain exactly 13 digits")