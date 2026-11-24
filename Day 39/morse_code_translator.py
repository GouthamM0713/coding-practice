morse = {
    'A': '.-', 'B': '-...', 'C': '-.-.',
    'D': '-..', 'E': '.', 'F': '..-.',
    'G': '--.', 'H': '....', 'I': '..',
    'J': '.---', 'K': '-.-', 'L': '.-..',
    'M': '--', 'N': '-.', 'O': '---',
    'P': '.--.', 'Q': '--.-', 'R': '.-.',
    'S': '...', 'T': '-', 'U': '..-',
    'V': '...-', 'W': '.--', 'X': '-..-',
    'Y': '-.--', 'Z': '--..',
    '0': '-----', '1': '.----',
    '2': '..---', '3': '...--',
    '4': '....-', '5': '.....',
    '6': '-....', '7': '--...',
    '8': '---..', '9': '----.',
    ' ': '/'
}

reverse_morse = {
    value: key for key, value in morse.items()
}


def encode(text):
    return " ".join(
        morse.get(char, "?")
        for char in text.upper()
    )


def decode(code):
    result = []

    for symbol in code.split():
        if symbol == "/":
            result.append(" ")
        else:
            result.append(reverse_morse.get(symbol, "?"))

    return "".join(result)


print("1. English to Morse")
print("2. Morse to English")

choice = input("Choose option: ")

if choice == "1":
    message = input("Enter English text: ")
    print("Morse:", encode(message))

elif choice == "2":
    message = input("Enter Morse code: ")
    print("English:", decode(message))

else:
    print("Invalid choice.")