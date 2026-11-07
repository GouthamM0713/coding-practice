filename = input("Enter file name: ")
search_word = input("Enter word to search: ").lower()

try:
    with open(filename, "r", encoding="utf-8") as file:
        content = file.readlines()

    count = 0

    for line_number, line in enumerate(content, start=1):
        words = line.lower().split()

        if search_word in words:
            print("Found on line:", line_number)
            count += words.count(search_word)

    print("Total occurrences:", count)

    if count == 0:
        print("Word not found!")

except FileNotFoundError:
    print("File does not exist!")

except OSError as error:
    print("File error:", error)