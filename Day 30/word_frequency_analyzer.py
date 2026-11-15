import re
from collections import Counter

text = input("Enter a paragraph: ")

words = re.findall(r"\b[\w']+\b", text.lower())

frequency = Counter(words)

print("\n--- Word Frequency Report ---")
print("Total words:", len(words))
print("Unique words:", len(frequency))

print("\nMost common words:")

for word, count in frequency.most_common(10):
    print(f"{word}: {count}")

if frequency:
    print("\nMost frequent word:", frequency.most_common(1)[0][0])
else:
    print("\nNo words found!")