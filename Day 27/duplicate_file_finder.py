import hashlib
from pathlib import Path


def calculate_hash(filepath):
    hasher = hashlib.sha256()

    with open(filepath, "rb") as file:
        for chunk in iter(lambda: file.read(4096), b""):
            hasher.update(chunk)

    return hasher.hexdigest()


folder = Path(input("Enter folder path: ").strip('"'))

if not folder.is_dir():
    print("Invalid folder path!")

else:
    file_groups = {}

    for filepath in folder.rglob("*"):
        if filepath.is_file():
            try:
                file_hash = calculate_hash(filepath)

                file_groups.setdefault(file_hash, []).append(filepath)

            except OSError:
                print("Could not read:", filepath)

    print("\n----- DUPLICATE FILES -----")

    found = False

    for files in file_groups.values():
        if len(files) > 1:
            found = True
            print("\nDuplicate group:")

            for filepath in files:
                print(filepath)

    if not found:
        print("No duplicate files found.")
        