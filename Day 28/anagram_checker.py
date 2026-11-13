def are_anagrams(word1, word2):
    word1 = word1.replace(" ", "").lower()
    word2 = word2.replace(" ", "").lower()

    return sorted(word1) == sorted(word2)


first = input("Enter first word: ")
second = input("Enter second word: ")

if are_anagrams(first, second):
    print("The words are anagrams!")
else:
    print("The words are not anagrams.")