
def caesar(text, shift):
    result = ""

    for char in text:
        if char.isalpha():
            base = ord('A') if char.isupper() else ord('a')
            result += chr((ord(char) - base + shift) % 26 + base)
        else:
            result += char

    return result


message = input("Enter message: ")
shift = int(input("Enter shift value: "))

encrypted = caesar(message, shift)

with open("encrypted_message.txt", "w") as file:
    file.write(encrypted)

print("Encrypted message:", encrypted)
print("Saved to encrypted_message.txt")

decrypted = caesar(encrypted, -shift)
print("Decrypted message:", decrypted)
