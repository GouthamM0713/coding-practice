import json
from pathlib import Path

filename = Path("tasks.json")


def load_tasks():
    if filename.exists():
        try:
            with open(filename, "r") as file:
                return json.load(file)
        except (json.JSONDecodeError, OSError):
            print("Could not read tasks file. Starting fresh.")

    return []


def save_tasks(tasks):
    with open(filename, "w") as file:
        json.dump(tasks, file, indent=4)


def display_tasks(tasks):
    if not tasks:
        print("No tasks available.")
        return

    for index, task in enumerate(tasks, start=1):
        status = "Completed" if task["done"] else "Pending"
        print(f"{index}. {task['name']} - {status}")


tasks = load_tasks()

while True:
    print("\n----- TASK MANAGER -----")
    print("1. Add Task")
    print("2. View Tasks")
    print("3. Complete Task")
    print("4. Delete Task")
    print("5. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        name = input("Enter task name: ").strip()

        if name:
            tasks.append({"name": name, "done": False})
            save_tasks(tasks)
            print("Task added!")
        else:
            print("Task name cannot be empty.")

    elif choice == "2":
        display_tasks(tasks)

    elif choice == "3":
        display_tasks(tasks)

        try:
            number = int(input("Enter task number: "))

            if 1 <= number <= len(tasks):
                tasks[number - 1]["done"] = True
                save_tasks(tasks)
                print("Task completed!")
            else:
                print("Invalid task number!")

        except ValueError:
            print("Enter a valid number.")

    elif choice == "4":
        display_tasks(tasks)

        try:
            number = int(input("Enter task number to delete: "))

            if 1 <= number <= len(tasks):
                removed = tasks.pop(number - 1)
                save_tasks(tasks)
                print("Deleted:", removed["name"])
            else:
                print("Invalid task number!")

        except ValueError:
            print("Enter a valid number.")

    elif choice == "5":
        print("Tasks saved. Goodbye!")
        break

    else:
        print("Invalid choice!")