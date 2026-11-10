import csv

input_file = "students.csv"
output_file = "cleaned_students.csv"

try:
    with open(input_file, "r", newline="") as file:
        reader = csv.reader(file)
        rows = list(reader)

    cleaned_rows = []
    seen = set()

    for row in rows:
        cleaned_row = [value.strip() for value in row]

        if not cleaned_row:
            continue

        key = tuple(cleaned_row)

        if key not in seen:
            seen.add(key)
            cleaned_rows.append(cleaned_row)

    with open(output_file, "w", newline="") as file:
        writer = csv.writer(file)
        writer.writerows(cleaned_rows)

    print("CSV cleaning completed!")
    print("Original rows:", len(rows))
    print("Cleaned rows:", len(cleaned_rows))
    print("Saved as:", output_file)

except FileNotFoundError:
    print("students.csv file not found.")

except Exception as error:
    print("Error:", error)