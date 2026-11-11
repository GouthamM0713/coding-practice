import sqlite3

connection = sqlite3.connect("students.db")
cursor = connection.cursor()

cursor.execute("""
CREATE TABLE IF NOT EXISTS students (
    id INTEGER PRIMARY KEY,
    name TEXT NOT NULL,
    course TEXT NOT NULL
)
""")

connection.commit()

while True:
    print("\nSTUDENT DATABASE")
    print("1. Add student")
    print("2. View students")
    print("3. Delete student")
    print("4. Exit")

    choice = input("Enter choice: ")

    if choice == "1":
        name = input("Enter student name: ").strip()
        course = input("Enter course: ").strip()

        if name and course:
            cursor.execute(
                "INSERT INTO students (name, course) VALUES (?, ?)",
                (name, course)
            )
            connection.commit()
            print("Student added successfully.")
        else:
            print("Name and course cannot be empty.")

    elif choice == "2":
        cursor.execute("SELECT * FROM students")
        records = cursor.fetchall()

        if records:
            for record in records:
                print(record)
        else:
            print("No student records found.")

    elif choice == "3":
        try:
            student_id = int(input("Enter student ID: "))

            cursor.execute(
                "DELETE FROM students WHERE id = ?",
                (student_id,)
            )
            connection.commit()

            if cursor.rowcount > 0:
                print("Student deleted successfully.")
            else:
                print("Student ID not found.")

        except ValueError:
            print("Enter a valid student ID.")

    elif choice == "4":
        print("Database closed.")
        break

    else:
        print("Invalid choice!")

connection.close()