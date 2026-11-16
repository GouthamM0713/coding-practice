import re

def validate_email(email):
    pattern = r"^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$"

    if re.match(pattern, email):
        print("Valid email address!")
    else:
        print("Invalid email address!")

email = input("Enter your email: ")
validate_email(email)