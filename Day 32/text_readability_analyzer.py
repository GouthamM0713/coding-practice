import re

text = input("Enter a paragraph: ")

words = re.findall(r"\b[\w'-]+\b", text)
sentences = re.split(r"[.!?]+", text)

sentences = [s for s in sentences if s.strip()]

syllables = 0

for word in words:
    word = word.lower()
    count = len(re.findall(r"[aeiouy]+", word))

    if word.endswith("e") and count > 1:
        count -= 1

    syllables += max(1, count)

if words and sentences:
    avg_words = len(words) / len(sentences)
    avg_syllables = syllables / len(words)

    score = (
        206.835
        - 1.015 * avg_words
        - 84.6 * avg_syllables
    )

    print("\n--- Readability Report ---")
    print("Words:", len(words))
    print("Sentences:", len(sentences))
    print("Estimated syllables:", syllables)
    print(f"Readability score: {score:.2f}")

else:
    print("Please enter meaningful text!")