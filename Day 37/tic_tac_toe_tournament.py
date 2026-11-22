
def play_game():
    board = [" "] * 9
    player = "X"

    for turn in range(9):
        print()
        for i in range(0, 9, 3):
            print("|".join(board[i:i+3]))

        try:
            position = int(input(f"Player {player}, choose 1-9: ")) - 1
        except ValueError:
            print("Enter a valid number")
            continue

        if not 0 <= position < 9 or board[position] != " ":
            print("Invalid position")
            continue

        board[position] = player

        wins = [
            (0, 1, 2), (3, 4, 5), (6, 7, 8),
            (0, 3, 6), (1, 4, 7), (2, 5, 8),
            (0, 4, 8), (2, 4, 6)
        ]

        if any(all(board[i] == player for i in line) for line in wins):
            print("Player", player, "wins!")
            return player

        player = "O" if player == "X" else "X"

    print("It's a draw!")
    return "Draw"


scores = {"X": 0, "O": 0}

rounds = int(input("Enter number of rounds: "))

for round_number in range(1, rounds + 1):
    print("\nROUND", round_number)
    winner = play_game()

    if winner in scores:
        scores[winner] += 1

print("\nTOURNAMENT RESULTS")
print("Player X:", scores["X"])
print("Player O:", scores["O"])

if scores["X"] > scores["O"]:
    print("Player X wins the tournament!")
elif scores["O"] > scores["X"]:
    print("Player O wins the tournament!")
else:
    print("Tournament tied!")
