candidates = {}
voters = set()

count = int(input("Enter number of candidates: "))

for i in range(count):
    name = input("Enter candidate name: ")
    candidates[name] = 0

while True:
    print("\n1. Cast Vote")
    print("2. View Results")
    print("3. Exit")

    choice = input("Enter choice: ")

    if choice == "1":
        voter_id = input("Enter voter ID: ")

        if voter_id in voters:
            print("You have already voted!")
            continue

        print("Candidates:", ", ".join(candidates))

        candidate = input("Enter candidate name: ")

        if candidate in candidates:
            candidates[candidate] += 1
            voters.add(voter_id)
            print("Vote recorded!")
        else:
            print("Invalid candidate!")

    elif choice == "2":
        for name, votes in candidates.items():
            print(name, ":", votes, "votes")

        if candidates:
            highest = max(candidates.values())
            winners = [
                name for name, votes in candidates.items()
                if votes == highest
            ]

            if highest == 0:
                print("No votes recorded yet.")
            elif len(winners) == 1:
                print("Winner:", winners[0])
            else:
                print("Tie between:", ", ".join(winners))

    elif choice == "3":
        break

    else:
        print("Invalid choice!")