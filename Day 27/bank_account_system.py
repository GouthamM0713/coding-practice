class BankAccount:
    def __init__(self, name, balance=0):
        self.name = name
        self.balance = balance

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            print("Amount deposited successfully!")
        else:
            print("Enter a valid amount.")

    def withdraw(self, amount):
        if amount <= 0:
            print("Enter a valid amount.")
        elif amount > self.balance:
            print("Insufficient balance!")
        else:
            self.balance -= amount
            print("Withdrawal successful!")

    def display(self):
        print("\nAccount Holder:", self.name)
        print(f"Available Balance: ₹{self.balance:.2f}")


name = input("Enter account holder name: ")
account = BankAccount(name)

while True:
    print("\n1. Deposit")
    print("2. Withdraw")
    print("3. Check Balance")
    print("4. Exit")

    choice = input("Enter your choice: ")

    try:
        if choice == "1":
            amount = float(input("Enter deposit amount: ₹"))
            account.deposit(amount)

        elif choice == "2":
            amount = float(input("Enter withdrawal amount: ₹"))
            account.withdraw(amount)

        elif choice == "3":
            account.display()

        elif choice == "4":
            print("Thank you for using our banking system!")
            break

        else:
            print("Invalid choice!")

    except ValueError:
        print("Please enter a valid number.")