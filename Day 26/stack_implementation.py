stack = []

while True:
    print("\nSTACK OPERATIONS")
    print("1. Push")
    print("2. Pop")
    print("3. Peek")
    print("4. Display")
    print("5. Exit")

    choice = input("Enter choice: ")

    if choice == "1":
        item = input("Enter item: ")
        stack.append(item)
        print("Item pushed successfully.")

    elif choice == "2":
        if stack:
            print("Removed:", stack.pop())
        else:
            print("Stack is empty.")

    elif choice == "3":
        if stack:
            print("Top element:", stack[-1])
        else:
            print("Stack is empty.")

    elif choice == "4":
        print("Stack:", stack)

    elif choice == "5":
        print("Exiting...")
        break

    else:
        print("Invalid choice!")