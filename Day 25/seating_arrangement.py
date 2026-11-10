import random

students = input(
    "Enter student names separated by commas: "
).split(",")

students = [name.strip() for name in students if name.strip()]

random.shuffle(students)

columns = int(input("Enter number of seats per row: "))

if columns <= 0:
    print("Number of seats must be positive.")
else:
    print("\nGenerated Seating Arrangement:")

    for i in range(0, len(students), columns):
        row = students[i:i + columns]

        print(" | ".join(row))