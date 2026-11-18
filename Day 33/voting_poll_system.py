
print("=== VOTING POLL SYSTEM ===")

candidates = {
    "Alice": 0,
    "Bob": 0,
    "Charlie": 0
}

while True:
    print("\nCandidates:")
    for name in candidates:
        print("-", name)

    vote = input("Enter candidate name (or 'stop' to finish): ").strip().title()

    if vote == "Stop":
        break

    if vote in candidates:
        candidates[vote] += 1
        print("Vote recorded!")
    else:
        print("Invalid candidate!")

print("\n=== FINAL RESULTS ===")

for name, votes in candidates.items():
    print(name, ":", votes, "votes")

winner = max(candidates, key=candidates.get)

if all(v == 0 for v in candidates.values()):
    print("No votes were recorded.")
elif list(candidates.values()).count(candidates[winner]) > 1:
    print("The poll ended in a tie.")
else:
    print("Winner:", winner)
