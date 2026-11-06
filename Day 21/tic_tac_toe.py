board = [" " for i in range(9)]

def display_board():
    print()
    for i in range(0, 9, 3):
        print(" | ".join(board[i:i + 3]))
        if i < 6:
            print("--+---+--")

player = "X"

while True:
    display_board()

    try:
        position = int(input(f"Player {player}, enter position (1-9): ")) - 1
    except ValueError:
        print("Enter a valid number!")
        continue

    if position < 0 or position > 8 or board[position] != " ":
        print("Invalid position!")
        continue

    board[position] = player

    winning_combinations = [
        (0, 1, 2), (3, 4, 5), (6, 7, 8),
        (0, 3, 6), (1, 4, 7), (2, 5, 8),
        (0, 4, 8), (2, 4, 6)
    ]

    if any(all(board[i] == player for i in combo)
           for combo in winning_combinations):
        display_board()
        print(f"Player {player} wins!")
        break

    if " " not in board:
        display_board()
        print("It's a draw!")
        break

    player = "O" if player == "X" else "X"