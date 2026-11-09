import time

sentence = "Python programming improves logical thinking"

print("Type the following sentence:")
print("\n", sentence)

input("\nPress Enter when ready...")

start = time.time()

typed = input("\nStart typing: ")

end = time.time()

elapsed = end - start

words = len(typed.split())

speed = (words / elapsed) * 60 if elapsed > 0 else 0

correct = sum(
    1 for a, b in zip(sentence, typed) if a == b
)

accuracy = (correct / len(sentence)) * 100

print("\nTyping Test Results")
print("Time:", round(elapsed, 2), "seconds")
print("Speed:", round(speed, 2), "WPM")
print("Accuracy:", round(accuracy, 2), "%")