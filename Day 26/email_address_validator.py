import re

email = input("Enter your email address: ").strip()

pattern = r"^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$"

if re.fullmatch(pattern, email):
    print("Valid email address!")
else:
    print("Invalid email address!")