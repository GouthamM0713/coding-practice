while True:
    print("\n--- Text Case Converter ---")
    print("1. UPPERCASE")
    print("2. lowercase")
    print("3. Title Case")
    print("4. Sentence case")
    print("5. Reverse text")
    print("6. Exit")

    choice = input("Enter choice: ")

    if choice == "6":
        break

    text = input("Enter your text: ")

    if choice == "1":
        result = text.upper()

    elif choice == "2":
        result = text.lower()

    elif choice == "3":
        result = text.title()

    elif choice == "4":
        result = text.capitalize()

    elif choice == "5":
        result = text[::-1]

    else:
        print("Invalid choice!")
        continue

    print("Converted text:", result)