
students = {}

count = int(input("Enter number of students: "))

if count <= 0:
    print("Invalid number of students")
else:
    for i in range(count):
        name = input("Enter student name: ")
        marks = float(input("Enter marks out of 100: "))

        if not 0 <= marks <= 100:
            print("Invalid marks")
            continue

        students[name] = marks

    ranking = sorted(
        students.items(),
        key=lambda student: student[1],
        reverse=True
    )

    print("\n----- STUDENT RANK LIST -----")

    for rank, (name, marks) in enumerate(ranking, start=1):
        print(rank, name, "-", marks)
