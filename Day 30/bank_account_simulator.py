class BankAccount:
    def __init__(self, name, balance=0):
        self.name = name
        self.balance = balance

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            print("Deposit successful!")
        else:
            print("Invalid amount!")

    def withdraw(self, amount):
        if 0 < amount <= self.balance:
            self.balance -= amount
            print("Withdrawal successful!")
        else:
            print("Insufficient balance or invalid amount!")

    def show_balance(self):
        print(f"Account holder: {self.name}")
        print(f"Balance: ₹{self.balance:.2f}")


name = input("Enter account holder name: ")
account = BankAccount(name)

while True:
    print("\n1. Deposit")
    print("2. Withdraw")
    print("3. Check balance")
    print("4. Exit")

    choice = input("Enter choice: ")

    if choice == "1":
        amount = float(input("Enter deposit amount: ₹"))
        account.deposit(amount)

    elif choice == "2":
        amount = float(input("Enter withdrawal amount: ₹"))
        account.withdraw(amount)

    elif choice == "3":
        account.show_balance()

    elif choice == "4":
        print("Thank you for using our bank!")
        break

    else:
        print("Invalid choice!")
        