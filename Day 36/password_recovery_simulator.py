
security_answer = "blue"

answer = input("What is your favourite colour? ").lower()

if answer == security_answer:
    print("Identity verified!")
    new_password = input("Enter your new password: ")

    if len(new_password) >= 8:
        print("Password successfully reset!")
    else:
        print("Password must contain at least 8 characters")
else:
    print("Incorrect security answer")
