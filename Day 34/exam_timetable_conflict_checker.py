
exam1 = input("Enter first exam subject: ")
time1 = input("Enter first exam time (HH:MM): ")

exam2 = input("Enter second exam subject: ")
time2 = input("Enter second exam time (HH:MM): ")

if time1 == time2:
    print("Timetable conflict detected!")
    print(exam1, "and", exam2, "are scheduled together.")
else:
    print("No timetable conflict.")
    print(exam1, ":", time1)
    print(exam2, ":", time2)
