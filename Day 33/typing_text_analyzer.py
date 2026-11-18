
print("=== BUS TICKET BOOKING ===")

name = input("Enter passenger name: ")
destination = input("Enter destination: ")
tickets = int(input("Number of tickets: "))

price = 250
total = tickets * price

print("\n=== BOOKING DETAILS ===")
print("Passenger:", name)
print("Destination:", destination)
print("Tickets:", tickets)
print("Total Amount: Rs.", total)
print("Booking successful!")

print("=== TYPING TEXT ANALYZER ===")

text = input("Enter a sentence or paragraph: ")

characters = len(text)
words = len(text.split())
spaces = text.count(" ")
vowels = 0
consonants = 0

for char in text.lower():
    if char.isalpha():
        if char in "aeiou":
            vowels += 1
        else:
            consonants += 1

print("\n=== TEXT ANALYSIS ===")
print("Characters:", characters)
print("Words:", words)
print("Spaces:", spaces)
print("Vowels:", vowels)
print("Consonants:", consonants)
print("Uppercase:", text.upper())
print("Lowercase:", text.lower())
