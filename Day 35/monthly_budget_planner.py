
income = float(input("Enter monthly income: "))
expenses = {}

while True:
    category = input("Enter expense category (or done): ")

    if category.lower() == "done":
        break

    amount = float(input("Enter expense amount: "))

    if amount < 0:
        print("Invalid amount")
        continue

    expenses[category] = expenses.get(category, 0) + amount

total = sum(expenses.values())
savings = income - total

print("\n----- MONTHLY BUDGET -----")

for category, amount in expenses.items():
    print(category, ":", amount)

print("Total expenses:", total)
print("Remaining savings:", savings)
