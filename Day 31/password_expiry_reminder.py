from datetime import datetime

password_name = input("Enter account name: ")
expiry_date = input("Enter password expiry date (YYYY-MM-DD): ")

try:
    expiry = datetime.strptime(expiry_date, "%Y-%m-%d").date()
    today = datetime.today().date()

    remaining_days = (expiry - today).days

    print("\n--- Password Expiry Report ---")
    print("Account:", password_name)

    if remaining_days < 0:
        print("Password has expired!")
    elif remaining_days == 0:
        print("Password expires today!")
    else:
        print("Days remaining:", remaining_days)

except ValueError:
    print("Invalid date format!")