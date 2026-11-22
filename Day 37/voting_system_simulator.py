
candidates = ["Alice", "Bob", "Charlie"]
votes = {name: 0 for name in candidates}

while True:
    print("\nCANDIDATES")

    for i, name in enumerate(candidates, 1):
        print(i, name)

    print("0 Exit")

    choice = int(input("Cast your vote: "))

    if choice == 0:
        break
    elif 1 <= choice <= len(candidates):
        votes[candidates[choice - 1]] += 1
        print("Vote recorded!")
    else:
        print("Invalid choice")

print("\nELECTION RESULTS")

for name, count in votes.items():
    print(name, ":", count, "votes")

if sum(votes.values()) > 0:
    highest = max(votes.values())
    winners = [name for name, count in votes.items()
               if count == highest]

    if len(winners) == 1:
        print("Winner:", winners[0])
    else:
        print("Tie between:", ", ".join(winners))
else:
    print("No votes were cast.")
