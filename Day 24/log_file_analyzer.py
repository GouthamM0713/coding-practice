from collections import Counter

filename = input("Enter log filename: ")

try:
    with open(filename, "r") as file:
        logs = file.readlines()

    count = Counter()

    for line in logs:
        for level in ["INFO", "WARNING", "ERROR", "DEBUG"]:
            if level in line.upper():
                count[level] += 1
                break

    print("\nLog Analysis Report")

    for level, total in count.items():
        print(level, ":", total)

    print("Total lines:", len(logs))

except FileNotFoundError:
    print("File not found")