import re

def validate_email(email):
    pattern = r"^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$"
    return re.fullmatch(pattern, email) is not None

while True:
    email = input("\nEnter email (or 'exit'): ")

    if email.lower() == "exit":
        break

    if validate_email(email):
        print("Valid email format!")
    else:
        print("Invalid email format!")