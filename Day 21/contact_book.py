contacts = {}

while True:
    print("\n1. Add Contact")
    print("2. Search Contact")
    print("3. Display Contacts")
    print("4. Delete Contact")
    print("5. Exit")

    choice = input("Enter choice: ")

    if choice == "1":
        name = input("Enter name: ")
        phone = input("Enter phone number: ")
        contacts[name] = phone
        print("Contact saved!")

    elif choice == "2":
        name = input("Enter name to search: ")
        print(contacts.get(name, "Contact not found"))

    elif choice == "3":
        for name, phone in contacts.items():
            print(name, ":", phone)

    elif choice == "4":
        name = input("Enter name to delete: ")
        if name in contacts:
            del contacts[name]
            print("Contact deleted!")
        else:
            print("Contact not found")

    elif choice == "5":
        break

    else:
        print("Invalid choice")