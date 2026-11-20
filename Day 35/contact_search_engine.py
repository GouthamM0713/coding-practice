
contacts = {}

while True:
    print("\n1. Add Contact")
    print("2. Search Contact")
    print("3. Display All")
    print("4. Exit")

    choice = input("Choose: ")

    if choice == "1":
        name = input("Enter name: ")
        phone = input("Enter phone number: ")
        contacts[name.lower()] = phone
        print("Contact saved")

    elif choice == "2":
        name = input("Search name: ").lower()
        print("Phone:", contacts.get(name, "Contact not found"))

    elif choice == "3":
        for name, phone in contacts.items():
            print(name, ":", phone)

    elif choice == "4":
        break

    else:
        print("Invalid choice")
