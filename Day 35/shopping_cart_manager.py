
cart = {}

while True:
    product = input("Enter product name (or done): ")

    if product.lower() == "done":
        break

    price = float(input("Enter product price: "))
    quantity = int(input("Enter quantity: "))

    if price < 0 or quantity <= 0:
        print("Invalid price or quantity")
        continue

    cart[product] = cart.get(product, 0) + price * quantity

print("\n----- SHOPPING BILL -----")

total = 0

for product, amount in cart.items():
    print(product, ":", round(amount, 2))
    total += amount

print("Total amount: ₹", round(total, 2))
