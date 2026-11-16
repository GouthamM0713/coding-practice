import os
from collections import Counter

folder = input("Enter folder path: ")

if os.path.isdir(folder):
    extensions = []

    for filename in os.listdir(folder):
        filepath = os.path.join(folder, filename)

        if os.path.isfile(filepath):
            extension = os.path.splitext(filename)[1].lower()

            if extension:
                extensions.append(extension)
            else:
                extensions.append("No extension")

    counts = Counter(extensions)

    print("\n--- File Extension Report ---")

    if counts:
        for extension, count in counts.most_common():
            print(f"{extension}: {count} file(s)")
    else:
        print("No files found!")

else:
    print("Folder does not exist!")