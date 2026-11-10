import hashlib


def calculate_checksum(filename):
    sha256 = hashlib.sha256()

    with open(filename, "rb") as file:
        while True:
            data = file.read(4096)

            if not data:
                break

            sha256.update(data)

    return sha256.hexdigest()


file1 = input("Enter first file path: ")
file2 = input("Enter second file path: ")

try:
    hash1 = calculate_checksum(file1)
    hash2 = calculate_checksum(file2)

    print("\nFile 1 Checksum:", hash1)
    print("File 2 Checksum:", hash2)

    if hash1 == hash2:
        print("Both files are identical.")
    else:
        print("Files are different.")

except FileNotFoundError:
    print("One or both files were not found.")