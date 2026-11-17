import os

def calculate_folder_size(folder):
    total_size = 0

    try:
        for item in os.scandir(folder):
            try:
                if item.is_file(follow_symlinks=False):
                    total_size += item.stat(
                        follow_symlinks=False
                    ).st_size

                elif item.is_dir(follow_symlinks=False):
                    total_size += calculate_folder_size(
                        item.path
                    )

            except OSError:
                continue

    except OSError:
        print("Cannot access:", folder)

    return total_size


folder = input("Enter folder path: ")

if os.path.isdir(folder):
    size = calculate_folder_size(folder)

    print("\nTotal Folder Size:")
    print(f"{size} bytes")
    print(f"{size / 1024:.2f} KB")
    print(f"{size / (1024 * 1024):.2f} MB")

else:
    print("Invalid folder path!")