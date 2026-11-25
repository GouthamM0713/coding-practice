import math


def encrypt(message, e, n):
    return [
        pow(ord(char), e, n)
        for char in message
    ]


def decrypt(cipher, d, n):
    return "".join(
        chr(pow(value, d, n))
        for value in cipher
    )


# Small demonstration keys
p = 61
q = 53

n = p * q
phi = (p - 1) * (q - 1)

e = 17

if math.gcd(e, phi) != 1:
    raise ValueError("Invalid public exponent.")

d = pow(e, -1, phi)

print("Public key:", (e, n))
print("Private key:", (d, n))

message = input("\nEnter message: ")

if any(ord(char) >= n for char in message):
    print("Message contains unsupported characters.")

else:
    encrypted = encrypt(message, e, n)

    print("Encrypted message:", encrypted)

    decrypted = decrypt(encrypted, d, n)

    print("Decrypted message:", decrypted)