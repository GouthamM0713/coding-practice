from collections import Counter
import re

sentence = input("Enter a paragraph: ")

words = re.findall(r"\b[\w']+\b", sentence.lower())
frequency = Counter(words)

print("\nWord Frequency:")

for word, count in frequency.most_common():
    print(word, ":", count)

print("\nTotal words:", len(words))
print("Unique words:", len(frequency))