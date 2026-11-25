def build_lps(pattern):
    lps = [0] * len(pattern)

    length = 0
    i = 1

    while i < len(pattern):

        if pattern[i] == pattern[length]:
            length += 1
            lps[i] = length
            i += 1

        elif length != 0:
            length = lps[length - 1]

        else:
            lps[i] = 0
            i += 1

    return lps


def kmp_search(text, pattern):
    if not pattern:
        return []

    lps = build_lps(pattern)

    i = 0
    j = 0
    positions = []

    while i < len(text):

        if text[i] == pattern[j]:
            i += 1
            j += 1

        if j == len(pattern):
            positions.append(i - j)
            j = lps[j - 1]

        elif i < len(text) and text[i] != pattern[j]:

            if j != 0:
                j = lps[j - 1]
            else:
                i += 1

    return positions


text = input("Enter text: ")
pattern = input("Enter pattern to search: ")

positions = kmp_search(text, pattern)

if positions:
    print("Pattern found at positions:", positions)
else:
    print("Pattern not found.")
    