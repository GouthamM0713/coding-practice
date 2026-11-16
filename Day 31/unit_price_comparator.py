products = []

n = int(input("Enter number of products: "))

for i in range(n):
    print(f"\nProduct {i + 1}")

    name = input("Product name: ")
    price = float(input("Total price: "))
    quantity = float(input("Quantity: "))

    if price < 0 or quantity <= 0:
        print("Invalid price or quantity!")
        continue

    unit_price = price / quantity

    products.append((name, unit_price))

if products:
    products.sort(key=lambda x: x[1])

    print("\nProducts ranked by unit price:")

    for name, price in products:
        print(f"{name}: {price:.2f} per unit")

    print("\nBest value:", products[0][0])