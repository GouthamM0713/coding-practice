class ShoppingCart:
    def __init__(self):
        self.items = {}

    def add_item(self, name, price, quantity):
        if price <= 0 or quantity <= 0:
            print("Price and quantity must be positive.")
            return

        if name in self.items:
            self.items[name]["quantity"] += quantity
        else:
            self.items[name] = {
                "price": price,
                "quantity": quantity
            }

        print(name, "added to cart!")

    def remove_item(self, name):
        if name in self.items:
            del self.items[name]
            print(name, "removed!")
        else:
            print("Item not found!")

    def display_cart(self):
        total = 0

        print("\n----- SHOPPING CART -----")

        for name, details in self.items.items():
            amount = details["price"] * details["quantity"]
            total += amount

            print(
                f"{name}: {details['quantity']} x "
                f"₹{details['price']:.2f} = ₹{amount:.2f}"
            )

        print("-------------------------")
        print(f"Total Amount: ₹{total:.2f}")


cart = ShoppingCart()

while True:
    print("\n1. Add Item")
    print("2. Remove Item")
    print("3. View Cart")
    print("4. Exit")

    choice = input("Choose an option: ")

    if choice == "1":
        name = input("Item name: ")

        try:
            price = float(input("Price: ₹"))
            quantity = int(input("Quantity: "))
            cart.add_item(name, price, quantity)
        except ValueError:
            print("Enter valid price and quantity!")

    elif choice == "2":
        name = input("Enter item name: ")
        cart.remove_item(name)

    elif choice == "3":
        cart.display_cart()

    elif choice == "4":
        print("Thank you for shopping!")
        break

    else:
        print("Invalid choice!")