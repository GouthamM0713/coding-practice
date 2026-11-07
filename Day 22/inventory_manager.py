inventory = {}

while True:
    print("\n1. Add Product")
    print("2. Update Stock")
    print("3. View Inventory")
    print("4. Exit")

    choice = input("Enter choice: ")

    if choice == "1":
        name = input("Product name: ")
        quantity = int(input("Quantity: "))

        inventory[name] = quantity
        print("Product added!")

    elif choice == "2":
        name = input("Product name: ")

        if name in inventory:
            quantity = int(input("New quantity: "))
            inventory[name] = quantity
            print("Stock updated!")
        else:
            print("Product not found!")

    elif choice == "3":
        for name, quantity in inventory.items():
            print(name, ":", quantity)

    elif choice == "4":
        break

    else:
        print("Invalid choice!")