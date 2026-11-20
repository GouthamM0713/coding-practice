
original = input("Enter original sentence: ")
typed = input("Enter typed sentence: ")

correct = 0

for i in range(min(len(original), len(typed))):
    if original[i] == typed[i]:
        correct += 1

if len(original) == 0:
    accuracy = 100 if len(typed) == 0 else 0
else:
    accuracy = (correct / len(original)) * 100

print("Correct characters:", correct)
print("Typing accuracy:", round(accuracy, 2), "%")
