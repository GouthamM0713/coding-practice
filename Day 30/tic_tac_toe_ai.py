def display(board):
    for i in range(0, 9, 3):
        print(" | ".join(board[i:i + 3]))
        if i < 6:
            print("--+---+--")


def winner(board, player):
    combinations = [
        (0, 1, 2), (3, 4, 5), (6, 7, 8),
        (0, 3, 6), (1, 4, 7), (2, 5, 8),
        (0, 4, 8), (2, 4, 6)
    ]

    return any(
        all(board[i] == player for i in combo)
        for combo in combinations
    )


def minimax(board, is_ai):
    if winner(board, "O"):
        return 1

    if winner(board, "X"):
        return -1

    if " " not in board:
        return 0

    if is_ai:
        best = -float("inf")

        for i in range(9):
            if board[i] == " ":
                board[i] = "O"
                best = max(best, minimax(board, False))
                board[i] = " "

        return best

    best = float("inf")

    for i in range(9):
        if board[i] == " ":
            board[i] = "X"
            best = min(best, minimax(board, True))
            board[i] = " "

    return best


def ai_move(board):
    best_score = -float("inf")
    move = None

    for i in range(9):
        if board[i] == " ":
            board[i] = "O"
            score = minimax(board, False)
            board[i] = " "

            if score > best_score:
                best_score = score
                move = i

    return move


board = [" "] * 9

print("You are X. Computer is O.")
print("Choose positions from 1 to 9.")

while True:
    display(board)

    try:
        position = int(input("\nYour move (1-9): ")) - 1

        if position not in range(9) or board[position] != " ":
            print("Invalid or occupied position!")
            continue

    except ValueError:
        print("Enter a number!")
        continue

    board[position] = "X"

    if winner(board, "X"):
        display(board)
        print("You win!")
        break

    if " " not in board:
        display(board)
        print("It's a draw!")
        break

    computer = ai_move(board)
    board[computer] = "O"

    print("\nComputer played:", computer + 1)

    if winner(board, "O"):
        display(board)
        print("Computer wins!")
        break

    if " " not in board:
        display(board)
        print("It's a draw!")
        break