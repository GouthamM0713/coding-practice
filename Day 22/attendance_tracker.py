students = {}

while True:
    print("\n1. Add Student")
    print("2. Mark Attendance")
    print("3. View Attendance")
    print("4. Exit")

    choice = input("Enter choice: ")

    if choice == "1":
        name = input("Student name: ")
        students[name] = {"present": 0, "total": 0}
        print("Student added!")

    elif choice == "2":
        name = input("Enter student name: ")

        if name in students:
            status = input("Present or Absent (P/A): ").upper()
            students[name]["total"] += 1

            if status == "P":
                students[name]["present"] += 1

            print("Attendance recorded!")
        else:
            print("Student not found!")

    elif choice == "3":
        for name, data in students.items():
            total = data["total"]
            present = data["present"]

            percentage = (
                present / total * 100 if total else 0
            )

            print(name, percentage, "%")

    elif choice == "4":
        break

    else:
        print("Invalid choice!")