
sentence = input("Enter a sentence: ")

words = sentence.split()
unique_words = []
seen = set()

for word in words:
    key = word.lower()

    if key not in seen:
        unique_words.append(word)
        seen.add(key)

print("Original:", sentence)
print("Without duplicates:", " ".join(unique_words))
