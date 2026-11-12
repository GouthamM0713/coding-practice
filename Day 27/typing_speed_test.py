import time

sentence = (
    "Python is a powerful programming language "
    "used for developing many applications."
)

print("----- TYPING SPEED TEST -----")
print("\nType the following sentence:")
print("\n" + sentence)

input("\nPress Enter when you are ready...")

start_time = time.perf_counter()
typed_text = input("\nStart typing: ")
end_time = time.perf_counter()

time_taken = end_time - start_time
minutes = time_taken / 60

words = len(typed_text.split())
speed = words / minutes if minutes > 0 else 0

correct = sum(
    1 for a, b in zip(sentence, typed_text) if a == b
)

accuracy = (correct / len(sentence)) * 100

print("\n----- YOUR RESULTS -----")
print(f"Time Taken: {time_taken:.2f} seconds")
print(f"Words Typed: {words}")
print(f"Typing Speed: {speed:.2f} WPM")
print(f"Accuracy: {accuracy:.2f}%")