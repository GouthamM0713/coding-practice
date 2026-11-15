import hashlib
from pathlib import Path

def calculate_hash(file_path):
    sha256 = hashlib.sha256()

    with file_path.open("rb") as file:
        for chunk in iter(lambda: file.read(4096), b""):
            sha256.update(chunk)

    return sha256.hexdigest()


folder = Path(input("Enter folder path: "))

if not folder.is_dir():
    print("Invalid folder!")
else:
    hashes = {}

    for file_path in folder.rglob("*"):
        if file_path.is_file() and not file_path.is_symlink():
            try:
                file_hash = calculate_hash(file_path)
                hashes.setdefault(file_hash, []).append(file_path)

            except OSError as error:
                print("Could not read:", file_path, error)

    print("\n--- Duplicate Files ---")

    found = False

    for files in hashes.values():
        if len(files) > 1:
            found = True
            print("\nDuplicate group:")

            for file_path in files:
                print(file_path)

    if not found:
        print("No duplicate files found!")