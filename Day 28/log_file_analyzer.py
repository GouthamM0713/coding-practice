from collections import Counter
from pathlib import Path


filename = Path(input("Enter log filename: "))

if not filename.is_file():
    print("Log file not found.")

else:
    counts = Counter()
    total_lines = 0

    try:
        with filename.open("r", encoding="utf-8") as file:
            for line in file:
                total_lines += 1

                for level in ("INFO", "WARNING", "ERROR"):
                    if level in line.upper():
                        counts[level] += 1
                        break

        print("\n----- LOG ANALYSIS -----")
        print("Total lines:", total_lines)
        print("INFO messages:", counts["INFO"])
        print("WARNING messages:", counts["WARNING"])
        print("ERROR messages:", counts["ERROR"])

    except OSError as error:
        print("Could not read file:", error)
        