import json
import os

FILE = "poll_results.json"

options = ["Python", "Java", "C++"]

if os.path.exists(FILE):
    with open(FILE, "r") as file:
        votes = json.load(file)
else:
    votes = {option: 0 for option in options}

while True:
    print("\n--- Programming Language Poll ---")

    for number, option in enumerate(options, 1):
        print(f"{number}. {option}")

    print("4. View results")
    print("5. Exit")

    choice = input("Enter choice: ")

    if choice in ["1", "2", "3"]:
        selected = options[int(choice) - 1]
        votes[selected] += 1

        with open(FILE, "w") as file:
            json.dump(votes, file, indent=4)

        print("Vote recorded!")

    elif choice == "4":
        total = sum(votes.values())

        print("\n--- Poll Results ---")

        for option, count in votes.items():
            percentage = count / total * 100 if total else 0
            print(f"{option}: {count} votes ({percentage:.1f}%)")

        print("Total votes:", total)

    elif choice == "5":
        break

    else:
        print("Invalid choice!")