import random


def create_deck():
    suits = ["Hearts", "Diamonds", "Clubs", "Spades"]

    ranks = [
        "2", "3", "4", "5", "6", "7",
        "8", "9", "10", "J", "Q", "K", "A"
    ]

    return [
        (rank, suit)
        for suit in suits
        for rank in ranks
    ]


def calculate_score(hand):
    score = 0
    aces = 0

    for rank, suit in hand:

        if rank in ("J", "Q", "K"):
            score += 10

        elif rank == "A":
            score += 11
            aces += 1

        else:
            score += int(rank)

    while score > 21 and aces:
        score -= 10
        aces -= 1

    return score


def display_hand(name, hand):
    print(f"\n{name}'s cards:")

    for rank, suit in hand:
        print(f"{rank} of {suit}")

    print("Score:", calculate_score(hand))


deck = create_deck()
random.shuffle(deck)

player = [deck.pop(), deck.pop()]
dealer = [deck.pop(), deck.pop()]

print("===== BLACKJACK =====")

display_hand("Player", player)

print("\nDealer's visible card:", dealer[0])

while calculate_score(player) < 21:

    choice = input("\nHit or Stand? ").lower()

    if choice == "hit":
        player.append(deck.pop())
        display_hand("Player", player)

    elif choice == "stand":
        break

    else:
        print("Invalid choice.")
        continue

    if calculate_score(player) > 21:
        break


if calculate_score(player) <= 21:

    while calculate_score(dealer) < 17:
        dealer.append(deck.pop())

display_hand("Player", player)
display_hand("Dealer", dealer)

player_score = calculate_score(player)
dealer_score = calculate_score(dealer)

print("\n===== RESULT =====")

if player_score > 21:
    print("Player busts! Dealer wins.")

elif dealer_score > 21:
    print("Dealer busts! Player wins.")

elif player_score > dealer_score:
    print("Player wins!")

elif dealer_score > player_score:
    print("Dealer wins!")

else:
    print("It's a tie!")