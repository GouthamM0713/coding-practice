
words = input("Enter words separated by spaces: ").lower().split()

groups = {}

for word in words:
    key = "".join(sorted(word))
    groups.setdefault(key, []).append(word)

print("\nAnagram Groups:")

for group in groups.values():
    print(group)
