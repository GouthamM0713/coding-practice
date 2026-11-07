from datetime import date

borrowed = date.fromisoformat(
    input("Enter borrowed date (YYYY-MM-DD): ")
)

returned = date.fromisoformat(
    input("Enter returned date (YYYY-MM-DD): ")
)

allowed_days = 14
fine_per_day = 2

days = (returned - borrowed).days
late_days = max(0, days - allowed_days)

fine = late_days * fine_per_day

print("Total borrowed days:", days)
print("Late days:", late_days)
print("Library fine: Rs.", fine)