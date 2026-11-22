
inventory = {
    "Laptop": 5,
    "Mouse": 20,
    "Keyboard": 8,
    "Monitor": 3,
    "Headphones": 15
}

limit = int(input("Enter minimum stock limit: "))

print("\nLOW STOCK ALERT")

for product, quantity in inventory.items():
    if quantity <= limit:
        print(product, "- Only", quantity, "left!")

print("\nComplete Inventory:")

for product, quantity in inventory.items():
    print(product, ":", quantity)
