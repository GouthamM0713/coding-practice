import difflib

file1 = input("Enter first file name: ")
file2 = input("Enter second file name: ")

try:
    with open(file1, "r") as f:
        text1 = f.readlines()

    with open(file2, "r") as f:
        text2 = f.readlines()

    difference = difflib.unified_diff(
        text1,
        text2,
        fromfile=file1,
        tofile=file2
    )

    result = list(difference)

    if result:
        print("\nDifferences found:\n")
        print(''.join(result))
    else:
        print("Both files are identical")

except FileNotFoundError:
    print("One or both files do not exist")