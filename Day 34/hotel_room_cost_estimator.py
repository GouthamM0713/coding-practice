
print("1. Standard Room - ₹1500/night")
print("2. Deluxe Room - ₹2500/night")
print("3. Suite Room - ₹4000/night")

choice = int(input("Choose room type: "))
nights = int(input("Enter number of nights: "))

if nights <= 0:
    print("Invalid number of nights")
else:
    if choice == 1:
        rate = 1500
    elif choice == 2:
        rate = 2500
    elif choice == 3:
        rate = 4000
    else:
        rate = 0

    if rate == 0:
        print("Invalid room choice")
    else:
        total = rate * nights
        print("Room cost: ₹", total)
