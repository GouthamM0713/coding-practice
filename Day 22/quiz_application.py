questions = [
    ("Which language is used for AI?", "python"),
    ("How many bits are in one byte?", "8"),
    ("What does CPU stand for?", "central processing unit"),
    ("Which symbol is used for comments in Python?", "#"),
    ("What is the result of 5 ** 2?", "25")
]

score = 0

for question, answer in questions:
    print("\n" + question)

    user_answer = input("Your answer: ").strip().lower()

    if user_answer == answer:
        print("Correct!")
        score += 1
    else:
        print("Wrong! Answer:", answer)

print("\nQUIZ COMPLETED")
print("Your score:", score, "/", len(questions))
print("Percentage:", score / len(questions) * 100, "%")