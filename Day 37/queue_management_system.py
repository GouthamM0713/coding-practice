
queue = []

while True:
    print("\n1. Add Person")
    print("2. Serve Person")
    print("3. View Queue")
    print("4. Exit")

    choice = input("Choose an option: ")

    if choice == "1":
        name = input("Enter person's name: ")
        queue.append(name)
        print(name, "added to queue")

    elif choice == "2":
        if queue:
            print("Serving:", queue.pop(0))
        else:
            print("Queue is empty")

    elif choice == "3":
        print("Current queue:", queue)

    elif choice == "4":
        break

    else:
        print("Invalid choice")
