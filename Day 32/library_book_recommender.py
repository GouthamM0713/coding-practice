books = {
    "fiction": [
        "The Alchemist",
        "Harry Potter",
        "The Hobbit"
    ],
    "science": [
        "A Brief History of Time",
        "Cosmos",
        "The Selfish Gene"
    ],
    "technology": [
        "Clean Code",
        "Python Crash Course",
        "The Pragmatic Programmer"
    ],
    "mystery": [
        "Gone Girl",
        "The Silent Patient",
        "Sherlock Holmes"
    ]
}

genre = input("Enter your favorite genre: ").lower()

if genre in books:
    print("\nRecommended Books:")

    for index, book in enumerate(books[genre], 1):
        print(index, book)

else:
    print("Sorry, genre not available!")