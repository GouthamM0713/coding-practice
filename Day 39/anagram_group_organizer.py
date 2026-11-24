from collections import defaultdict


def group_anagrams(words):
    groups = defaultdict(list)

    for word in words:
        key = "".join(sorted(word.lower()))
        groups[key].append(word)

    return list(groups.values())


words = input(
    "Enter words separated by spaces: "
).split()

groups = group_anagrams(words)

print("\nAnagram Groups:")

for index, group in enumerate(groups, start=1):
    print(f"Group {index}: {group}")