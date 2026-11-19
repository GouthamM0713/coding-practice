
text = input("Enter your text: ")

print("\n1. Uppercase")
print("2. Lowercase")
print("3. Title Case")
print("4. Sentence Case")

choice = int(input("Choose an option: "))

if choice == 1:
    result = text.upper()
elif choice == 2:
    result = text.lower()
elif choice == 3:
    result = text.title()
elif choice == 4:
    result = text.capitalize()
else:
    result = None

if result is not None:
    print("Converted text:", result)
else:
    print("Invalid choice")
