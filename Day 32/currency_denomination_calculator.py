amount = int(input("Enter amount: "))

denominations = [
    500, 200, 100, 50, 20, 10, 5, 2, 1
]

print("\nCurrency Breakdown:")

for note in denominations:
    count = amount // note

    if count > 0:
        print(f"₹{note}: {count}")

        amount %= note

print("Remaining amount:", amount)