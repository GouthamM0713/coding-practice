password = input("Enter your password: ")

if len(password) <= 2:
    masked = "*" * len(password)
else:
    masked = password[0] + "*" * (len(password) - 2) + password[-1]

print("Masked password:", masked)