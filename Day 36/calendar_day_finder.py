
import datetime

date_text = input("Enter date (DD-MM-YYYY): ")

try:
    date = datetime.datetime.strptime(date_text, "%d-%m-%Y")
    print("Day of the week:", date.strftime("%A"))
except ValueError:
    print("Invalid date format or date")
