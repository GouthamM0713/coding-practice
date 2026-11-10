bids = {}

print("Welcome to the Auction System!")

while True:
    name = input("\nEnter bidder name: ")

    if not name.strip():
        print("Name cannot be empty.")
        continue

    try:
        amount = float(input("Enter your bid amount: "))

        if amount <= 0:
            print("Bid must be greater than zero.")
            continue

        if name in bids:
            bids[name] = max(bids[name], amount)
        else:
            bids[name] = amount

    except ValueError:
        print("Please enter a valid amount.")
        continue

    choice = input("Are there more bidders? (yes/no): ").lower()

    if choice != "yes":
        break

if bids:
    winner = max(bids, key=bids.get)

    print("\nAuction Results")
    print("----------------")
    print("Winner:", winner)
    print("Winning Bid: ₹", bids[winner])
else:
    print("No valid bids received.")