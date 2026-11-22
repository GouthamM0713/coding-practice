
from collections import Counter
import re

sentence = input("Enter a paragraph: ").lower()

words = re.findall(r"\b[\w']+\b", sentence)
frequency = Counter(words)

print("\nWORD FREQUENCY CHART")

for word, count in frequency.most_common():
    print(f"{word:15} {'*' * count} ({count})")
