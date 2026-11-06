name = input("Enter student name: ")

marks = []

for i in range(5):
    mark = float(input(f"Enter subject {i + 1} marks: "))
    marks.append(mark)

total = sum(marks)
average = total / 5

if average >= 90:
    grade = "A"
elif average >= 75:
    grade = "B"
elif average >= 60:
    grade = "C"
elif average >= 40:
    grade = "D"
else:
    grade = "Fail"

print("\nStudent Name:", name)
print("Total Marks:", total)
print("Average:", average)
print("Grade:", grade)