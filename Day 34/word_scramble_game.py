
import random

words = ["python", "computer", "programming", "keyboard", "internet"]

word = random.choice(words)
scrambled = "".join(random.sample(word, len(word)))

print("Unscramble this word:", scrambled)

attempts = 3

while attempts > 0:
    guess = input("Your guess: ").lower()

    if guess == word:
        print("Correct! You won!")
        break
    else:
        attempts -= 1
        print("Wrong guess! Attempts left:", attempts)

if attempts == 0:
    print("Game over! The word was:", word)
