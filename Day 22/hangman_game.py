import random

words = ["computer", "python", "keyboard", "programming",
         "internet", "software"]

word = random.choice(words)
guessed = set()
attempts = 6

while attempts > 0:
    display = ""

    for letter in word:
        display += letter if letter in guessed else "_"

    print("\nWord:", display)
    print("Attempts remaining:", attempts)

    if "_" not in display:
        print("Congratulations! You won!")
        break

    guess = input("Guess a letter: ").lower()

    if len(guess) != 1 or not guess.isalpha():
        print("Enter one valid letter!")
        continue

    if guess in guessed:
        print("You already guessed that letter!")
        continue

    guessed.add(guess)

    if guess not in word:
        attempts -= 1
        print("Wrong guess!")

else:
    print("\nGame over! The word was:", word)