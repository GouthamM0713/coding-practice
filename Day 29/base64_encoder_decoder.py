import base64

print("1. Encode")
print("2. Decode")

choice = input("Enter choice: ")

if choice == "1":
    message = input("Enter text: ")
    encoded = base64.b64encode(message.encode()).decode()
    print("Encoded text:", encoded)

elif choice == "2":
    message = input("Enter Base64 text: ")

    try:
        decoded = base64.b64decode(
            message, validate=True
        ).decode()
        print("Decoded text:", decoded)
    except Exception:
        print("Invalid Base64 input!")

else:
    print("Invalid choice!")