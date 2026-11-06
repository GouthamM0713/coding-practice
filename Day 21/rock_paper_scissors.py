import random

choices = ["rock", "paper", "scissors"]

user_score = 0
computer_score = 0

for i in range(5):
    user = input("Choose rock, paper, or scissors: ").lower()
    computer = random.choice(choices)

    print("Computer chose:", computer)

    if user not in choices:
        print("Invalid choice!")
        continue

    if user == computer:
        print("It's a tie!")

    elif (
        (user == "rock" and computer == "scissors") or
        (user == "paper" and computer == "rock") or
        (user == "scissors" and computer == "paper")
    ):
        print("You win!")
        user_score += 1

    else:
        print("Computer wins!")
        computer_score += 1

print("\nYour score:", user_score)
print("Computer score:", computer_score)