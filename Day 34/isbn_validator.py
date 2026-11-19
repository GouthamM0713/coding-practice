
isbn = input("Enter ISBN-10: ").replace("-", "").replace(" ", "")

if len(isbn) != 10:
    print("Invalid ISBN length")
else:
    total = 0

    for i in range(10):
        if i == 9 and isbn[i].upper() == "X":
            digit = 10
        elif isbn[i].isdigit():
            digit = int(isbn[i])
        else:
            print("Invalid ISBN characters")
            break

        total += digit * (10 - i)
    else:
        if total % 11 == 0:
            print("Valid ISBN-10")
        else:
            print("Invalid ISBN-10")
