import csv
from pathlib import Path
from datetime import date

FILE = Path("attendance.csv")

if not FILE.exists():
    with FILE.open("w", newline="", encoding="utf-8") as file:
        writer = csv.writer(file)
        writer.writerow(["Date", "Student", "Status"])

while True:
    name = input("\nEnter student name (or exit): ").strip()

    if name.lower() == "exit":
        break

    if not name:
        print("Name cannot be empty!")
        continue

    status = input("Present or Absent (P/A): ").upper()

    if status not in ("P", "A"):
        print("Invalid attendance status!")
        continue

    with FILE.open("a", newline="", encoding="utf-8") as file:
        writer = csv.writer(file)
        writer.writerow([
            date.today().isoformat(),
            name,
            "Present" if status == "P" else "Absent"
        ])

    print("Attendance recorded!")

print("\n--- Attendance Report ---")

records = {}

with FILE.open("r", newline="", encoding="utf-8") as file:
    reader = csv.DictReader(file)

    for row in reader:
        name = row["Student"]
        records.setdefault(name, [0, 0])

        if row["Status"] == "Present":
            records[name][0] += 1
        else:
            records[name][1] += 1

for name, (present, absent) in sorted(records.items()):
    total = present + absent
    percentage = present / total * 100 if total else 0

    print(
        f"{name}: Present={present}, Absent={absent}, "
        f"Attendance={percentage:.1f}%"
    )