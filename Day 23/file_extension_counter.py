import os
from collections import Counter

folder = input("Enter folder path: ")

try:
    extensions = []

    for filename in os.listdir(folder):
        full_path = os.path.join(folder, filename)

        if os.path.isfile(full_path):
            extension = os.path.splitext(filename)[1].lower()

            extensions.append(extension if extension else "No extension")

    counts = Counter(extensions)

    print("\nFile Extension Report:")

    for extension, count in counts.items():
        print(extension, ":", count)

    print("\nTotal files:", len(extensions))

except FileNotFoundError:
    print("Folder not found.")

except PermissionError:
    print("Permission denied.")