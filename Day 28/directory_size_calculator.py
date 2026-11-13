from pathlib import Path


def calculate_directory_size(folder):
    total_size = 0

    for item in folder.rglob("*"):
        if item.is_file():
            try:
                total_size += item.stat().st_size
            except OSError:
                print("Could not access:", item)

    return total_size


folder = Path(input("Enter directory path: ").strip('"'))

if folder.is_dir():
    size = calculate_directory_size(folder)

    print("\nDirectory:", folder)
    print(f"Total size: {size:,} bytes")
    print(f"Total size: {size / 1024:.2f} KB")
    print(f"Total size: {size / (1024 * 1024):.2f} MB")

else:
    print("Invalid directory path.")
    