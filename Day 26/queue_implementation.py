from collections import deque

queue = deque()

while True:
    print("\nQUEUE OPERATIONS")
    print("1. Enqueue")
    print("2. Dequeue")
    print("3. Front")
    print("4. Display")
    print("5. Exit")

    choice = input("Enter choice: ")

    if choice == "1":
        item = input("Enter item: ")
        queue.append(item)
        print("Item added successfully.")

    elif choice == "2":
        if queue:
            print("Removed:", queue.popleft())
        else:
            print("Queue is empty.")

    elif choice == "3":
        if queue:
            print("Front element:", queue[0])
        else:
            print("Queue is empty.")

    elif choice == "4":
        print("Queue:", list(queue))

    elif choice == "5":
        print("Exiting...")
        break

    else:
        print("Invalid choice!")