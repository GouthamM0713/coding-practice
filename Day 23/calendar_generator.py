import calendar

year = int(input("Enter year: "))
month = int(input("Enter month (1-12): "))

if year < 1 or month < 1 or month > 12:
    print("Invalid year or month.")
else:
    print("\nMonthly Calendar")
    print(calendar.month(year, month))