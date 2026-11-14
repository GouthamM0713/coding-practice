from pathlib import Path

def print_tree(directory, prefix=""):
    try:
        items = sorted(
            directory.iterdir(),
            key=lambda item: (item.is_file(), item.name.lower())
        )
    except PermissionError:
        print(prefix + "[Permission denied]")
        return

    for index, item in enumerate(items):
        last = index == len(items) - 1
        connector = "└── " if last else "├── "

        print(prefix + connector + item.name)

        if item.is_dir():
            extension = "    " if last else "│   "
            print_tree(item, prefix + extension)

path = Path(input("Enter folder path: "))

if path.exists() and path.is_dir():
    print(path.name)
    print_tree(path)
else:
    print("Invalid directory!")