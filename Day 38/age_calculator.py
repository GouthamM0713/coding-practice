from datetime import date

birth_year = int(input("Enter birth year: "))
birth_month = int(input("Enter birth month: "))
birth_day = int(input("Enter birth day: "))

today = date.today()
birth_date = date(birth_year, birth_month, birth_day)

age = today.year - birth_date.year
if (today.month, today.day) < (birth_date.month, birth_date.day):
    age -= 1

print("Your age is:", age, "years")