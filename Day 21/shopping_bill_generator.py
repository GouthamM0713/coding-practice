items = []

while True:
    name = input("Enter item name (or 'done' to finish): ")

    if name.lower() == "done":
        break

    price = float(input("Enter item price: "))
    quantity = int(input("Enter quantity: "))

    items.append((name, price, quantity))

print("\n========== SHOPPING BILL ==========")

total = 0

for name, price, quantity in items:
    amount = price * quantity
    total += amount

    print(f"{name}: {quantity} x {price:.2f} = {amount:.2f}")

print("-----------------------------------")
print(f"Total Amount: Rs. {total:.2f}")
print("===================================")