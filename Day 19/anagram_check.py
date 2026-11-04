a = input("Enter first string: ").lower()
b = input("Enter second string: ").lower()

if sorted(a) == sorted(b):
    print("Anagrams")
else:
    print("Not Anagrams")