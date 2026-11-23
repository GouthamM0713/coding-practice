students = int(input("Enter number of students: "))
grades = []

for i in range(students):
    mark = float(input(f"Enter marks for student {i + 1}: "))
    grades.append(mark)

print("\nGrade Distribution")

print("A Grade:", sum(1 for m in grades if m >= 90))
print("B Grade:", sum(1 for m in grades if 75 <= m < 90))
print("C Grade:", sum(1 for m in grades if 60 <= m < 75))
print("D Grade:", sum(1 for m in grades if 40 <= m < 60))
print("Fail:", sum(1 for m in grades if m < 40))