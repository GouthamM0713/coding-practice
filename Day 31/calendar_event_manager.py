import json
import os

FILE = "calendar_events.json"

def load_events():
    if os.path.exists(FILE):
        with open(FILE, "r") as file:
            return json.load(file)
    return []

def save_events(events):
    with open(FILE, "w") as file:
        json.dump(events, file, indent=4)

events = load_events()

while True:
    print("\n1. Add Event")
    print("2. View Events")
    print("3. Delete Event")
    print("4. Exit")

    choice = input("Choose an option: ")

    if choice == "1":
        date = input("Enter date (YYYY-MM-DD): ")
        event = input("Enter event name: ")

        events.append({
            "date": date,
            "event": event
        })

        save_events(events)
        print("Event added!")

    elif choice == "2":
        for index, item in enumerate(events, 1):
            print(index, item["date"], item["event"])

    elif choice == "3":
        for index, item in enumerate(events, 1):
            print(index, item["event"])

        number = int(input("Enter event number: "))

        if 1 <= number <= len(events):
            events.pop(number - 1)
            save_events(events)
            print("Event deleted!")
        else:
            print("Invalid event number!")

    elif choice == "4":
        break

    else:
        print("Invalid choice!")