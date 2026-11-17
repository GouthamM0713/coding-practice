import hashlib

password = input("Enter password: ")

hashed_password = hashlib.sha256(
    password.encode()
).hexdigest()

print("\n--- Password Hash ---")
print("SHA-256:", hashed_password)

verification = input("\nRe-enter password: ")

check_hash = hashlib.sha256(
    verification.encode()
).hexdigest()

if check_hash == hashed_password:
    print("Password matches!")
else:
    print("Password does not match!")