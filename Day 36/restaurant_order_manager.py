
menu = {
    "idli": 30,
    "dosa": 50,
    "poori": 40,
    "meals": 100,
    "coffee": 20
}

order = {}

print("MENU")
for item, price in menu.items():
    print(item, "- ₹", price)

while True:
    item = input("\nEnter item (or done): ").lower()

    if item == "done":
        break

    if item not in menu:
        print("Item not available")
        continue

    quantity = int(input("Enter quantity: "))

    if quantity <= 0:
        print("Invalid quantity")
        continue

    order[item] = order.get(item, 0) + quantity

print("\n----- BILL -----")
total = 0

for item, quantity in order.items():
    amount = menu[item] * quantity
    print(item, "x", quantity, "=", amount)
    total += amount

print("Total bill: ₹", total)
