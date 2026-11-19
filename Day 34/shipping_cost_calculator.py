
weight = float(input("Enter package weight in kg: "))

print("1. Standard Delivery")
print("2. Express Delivery")

choice = int(input("Choose delivery type: "))

if weight <= 0:
    print("Invalid weight")
elif choice == 1:
    cost = weight * 40
    print("Standard shipping cost: ₹", cost)
elif choice == 2:
    cost = weight * 70
    print("Express shipping cost: ₹", cost)
else:
    print("Invalid choice")
