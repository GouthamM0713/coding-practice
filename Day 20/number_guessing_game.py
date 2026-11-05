import random

secret = random.randint(1, 100)
attempts = 0

while True:
    guess = int(input("Guess a number (1-100): "))
    attempts += 1

    if guess == secret:
        print("Congratulations! Correct guess.")
        print("Attempts:", attempts)
        break
    elif guess < secret:
        print("Too Low! Try Again.")
    else:
        print("Too High! Try Again.")