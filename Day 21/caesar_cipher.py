message = input("Enter your message: ")
shift = int(input("Enter shift value: "))

result = ""

for char in message:
    if char.isalpha():
        base = ord('A') if char.isupper() else ord('a')
        result += chr((ord(char) - base + shift) % 26 + base)
    else:
        result += char

print("Encrypted Message:", result)