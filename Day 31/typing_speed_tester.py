import time

sentence = "Python programming improves logical thinking"

print("Type the following sentence:")
print(sentence)

input("\nPress Enter when ready...")

start = time.time()

typed_text = input("\nStart typing: ")

end = time.time()

duration = end - start

words = len(typed_text.split())

minutes = duration / 60

wpm = words / minutes if minutes > 0 else 0

correct = sum(
    1 for a, b in zip(sentence, typed_text) if a == b
)

accuracy = (correct / len(sentence)) * 100

print("\n--- Typing Report ---")
print(f"Time: {duration:.2f} seconds")
print(f"Speed: {wpm:.2f} WPM")
print(f"Accuracy: {accuracy:.2f}%")