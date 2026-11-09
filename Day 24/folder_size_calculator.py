import os

folder = input("Enter folder path: ")

total_size = 0
file_count = 0

if os.path.isdir(folder):

    for root, dirs, files in os.walk(folder):
        for filename in files:
            path = os.path.join(root, filename)

            try:
                total_size += os.path.getsize(path)
                file_count += 1
            except OSError:
                continue

    print("Total files:", file_count)
    print("Folder size:", round(total_size / (1024 * 1024), 2), "MB")

else:
    print("Invalid folder path")