expenses = []

while True:
    print("\n1. Add Expense")
    print("2. View Expenses")
    print("3. Total Expenses")
    print("4. Exit")

    choice = input("Enter choice: ")

    if choice == "1":
        name = input("Enter expense name: ")
        amount = float(input("Enter amount: "))
        expenses.append((name, amount))
        print("Expense added successfully!")

    elif choice == "2":
        if not expenses:
            print("No expenses recorded.")
        else:
            for name, amount in expenses:
                print(name, ":", amount)

    elif choice == "3":
        total = sum(amount for name, amount in expenses)
        print("Total expenses:", total)

    elif choice == "4":
        break

    else:
        print("Invalid choice!")