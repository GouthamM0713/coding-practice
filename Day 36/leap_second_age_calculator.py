
from datetime import date
from calendar import monthrange

birth = input("Enter birth date (DD-MM-YYYY): ")

try:
    d, m, y = map(int, birth.split("-"))
    birth_date = date(y, m, d)
    today = date.today()

    if birth_date > today:
        print("Birth date cannot be in the future")
    else:
        years = today.year - birth_date.year
        months = today.month - birth_date.month
        days = today.day - birth_date.day

        if days < 0:
            months -= 1
            previous_month = today.month - 1 or 12
            previous_year = today.year if today.month > 1 else today.year - 1
            days += monthrange(previous_year, previous_month)[1]

        if months < 0:
            years -= 1
            months += 12

        print("Age:", years, "years,", months, "months,", days, "days")
except ValueError:
    print("Invalid date")
