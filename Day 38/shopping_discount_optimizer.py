price = float(input("Enter product price: "))
quantity = int(input("Enter quantity: "))

total = price * quantity

if total >= 5000:
    discount = 20
elif total >= 3000:
    discount = 15
elif total >= 1000:
    discount = 10
else:
    discount = 0

discount_amount = total * discount / 100
final_amount = total - discount_amount

print("\nShopping Summary")
print("Original amount:", total)
print("Discount:", discount, "%")
print("Discount amount:", discount_amount)
print("Final amount:", final_amount)